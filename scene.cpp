#include "scene.h"
#include "colony.h"
#include "food.h"
#include "ant.h"
#include "graphics.h"

#include <SDL2/SDL.h>
#include <algorithm>
#include <sstream>

Scene *Block::mainScene;

Scene::Scene(Graphics *gr, int w, int h) :
    fieldWidth( w ),
    fieldHeight( h ),
    quit(false),
    graphics( gr ),
    foodColor( ColorBlue ),
    FPS( 0.0 ),
    dying( false )

{
    Block::mainScene = this;
    Colony *red   = new Colony( this, ColorRed  , 440, 10 ),
           *black = new Colony( this, ColorBlack,  15, 10 );
    new Base( 15,  15, red);
    new Base( FIELD_WIDTH - 15, FIELD_HEIGHT - 15, black);
    for(int i=0;i<OBJECTS;++i)
    {
        new Ant( rand() % 31 - 15 + black->bases[0]->getX(),
                 rand() % 31 - 15 + black->bases[0]->getY(),
                 black );
        new Ant( rand() % 31 - 15 + red->bases[0]->getX(),
                 rand() % 31 - 15 + red->bases[0]->getY(),
                 red );
        new Food();
    }
}

Scene::~Scene()
{
  dying = true;
  for( int i = food.size() - 1; i >= 0; --i )
      delete food[i];
  for( int i = colonies.size() - 1; i >= 0; --i )
      delete colonies[i];
}

void Scene::forgetFood( Food *what )
{
    SDL_assert( what != NULL );
    food.erase( std::remove( food.begin(), food.end(), what ), food.end() );
    if( !dying )
        new Food();
}

void Scene::forgetColony(Colony *what)
{
    SDL_assert( what != NULL );
    colonies.erase( std::remove( colonies.begin(), colonies.end(), what ), colonies.end() );
}

void Scene::drawField()
{
   // glColor3f(0.0,1.0,0.0);
   // glBegin(GL_LINES);
   //  for (int i=0; i<WIDTH; i+=scale)
   //    {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
   //  for (int j=0; j<=HEIGHT; j+=scale)
   //    {glVertex2f(0,j); glVertex2f(WIDTH,j);}
   //  glEnd();
}

void Scene::processEvents()
{
    SDL_Event Event;
    while( SDL_PollEvent( &Event ) )
    {
        switch( Event.type )
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch( Event.key.keysym.scancode )
            {
            case SDL_SCANCODE_Z:
                allFoods();
                break;
            case SDL_SCANCODE_M:
                SDL_assert(false);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Scene::action()
{
    for( unsigned int colonyNum = 0; colonyNum < colonies.size(); ++colonyNum )
    {
        for( unsigned int antNum = 0; antNum < colonies[colonyNum]->ants.size(); ++antNum )
        {
            colonies[colonyNum]->ants[antNum]->action();
        }
    }
}

void Scene::draw()
{
    graphics->setColor( ColorYellow );
    int result = SDL_RenderClear( graphics->renderer );
    SDL_assert( result >= 0 );
    drawField();
    for(unsigned int i=0;i<colonies.size();++i)
    {
        colonies[i]->draw();
    }
    for (unsigned int i=0;i<food.size();i++)
    {
        food[i]->draw();
    }
    std::stringstream ss;
    ss << "FPS: " << FPS;
    graphics->outText( 200, 10, ss.str().c_str(), ColorGreen );
    SDL_RenderPresent( graphics->renderer );
}

void Scene::allFoods()
{
    for ( unsigned int i = 0; i < food.size(); ++i )
    {
        delete food[0];
    }

}
