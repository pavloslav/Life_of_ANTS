#include "scene.h"
#include "colony.h"
#include "food.h"
#include "ant.h"
#include "graphics.h"

#include <SDL2/SDL.h>
#include <algorithm>
#include <sstream>
#include <cstring>

Scene *Block::mainScene;

Scene::Scene(Graphics *gr, int w, int h) :
    fieldWidth( w ),
    fieldHeight( h ),
    quit(false),
    graphics( gr ),
    foodColor( ColorBlue ),
    FPS( 0.0 ),
    dying( false ),
    labelFPS( gr, gr->font, 200, 10, ColorGreen )

{
    Block::mainScene = this;
    Colony *red   = new Colony( this, ColorRed  , 440, 10 ),
           *black = new Colony( this, ColorBlack,  15, 10 );
    new Base( 15,  15, "Red", red );
    new Base( FIELD_WIDTH - 15, FIELD_HEIGHT - 15, "Black", black);
    std::stringstream name;
    for(int i=0;i<OBJECTS;++i)
    {
        name.str( "" );
        name << "Ant_" << i;
        new Ant( rand() % 31 - 15 + black->bases[0]->getX(),
                 rand() % 31 - 15 + black->bases[0]->getY(),
                 name.str(),
                 black );
        new Ant( rand() % 31 - 15 + red->bases[0]->getX(),
                 rand() % 31 - 15 + red->bases[0]->getY(),
                 name.str(),
                 red );
        name.str( "" );
        name << "Food_" << i;
        new Food( name.str() );
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
    std::string name = what->getName();
    food.erase( std::remove( food.begin(), food.end(), what ), food.end() );
    if( !dying )
        new Food( name );
}

void Scene::forgetColony(Colony *what)
{
    SDL_assert( what != NULL );
    colonies.erase( std::remove( colonies.begin(), colonies.end(), what ), colonies.end() );
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
    labelFPS.setText("FPS: ") << FPS;
}

void Scene::draw()
{
    graphics->setColor( ColorYellow );
    int result = SDL_RenderClear( graphics->renderer );
    SDL_assert( result >= 0 );
    for(unsigned int i=0;i<colonies.size();++i)
    {
        colonies[i]->draw();
    }
    for (unsigned int i=0;i<food.size();i++)
    {
        food[i]->draw();
    }
    labelFPS.draw();
    SDL_RenderPresent( graphics->renderer );
}

void Scene::allFoods()
{
    for ( unsigned int i = 0; i < food.size(); ++i )
    {
        delete food[0];
    }

}
