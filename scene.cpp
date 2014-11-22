#include "scene.h"
#include "colony.h"
#include "food.h"
#include "ant.h"
#include <SDL2/SDL.h>

Scene *Block::mainScene;

Scene::Scene(Graphics *gr) :
    black( this,   0, 0, 0,  15, 10 ),
    red  ( this, 255, 0, 0, 300, 10 ),
    delay ( 100 ),
    scale ( 1.0 ),
    winScale ( 5 ),
    winPosX ( 200 ),
    winPosY ( 100 ),
    quit(false),
    graphics( gr )
{
    colonies.push_back( &black );
    colonies.push_back( &red );
    new Base( 15,  15, &red);
    new Base( FIELD_WIDTH - 15, FIELD_HEIGHT-15, &black);
    for(int i=0;i<20;++i)
    {
        new Ant( rand()%30 + 150,
                 rand()%30 + 150,
                 &black );
        new Ant( rand()% 30,
                 rand()% 30,
                 &red );
        food.push_back( new Food() );
    }
    allFoods();
}

Scene::~Scene()
{
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
    while(SDL_PollEvent(&Event))
    {
        switch( Event.type )
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            if( Event.key.keysym.sym == SDLK_z )
                allFoods();
            break;
        }
    }
}

void Scene::action()
{
    for(int i=0;i<20;++i){
      red.ants[i]->action();
      black.ants[i]->action();
    }
}

void Scene::draw()
{
    SDL_SetRenderDrawColor( graphics->canvas, 255, 255, 128, 255 );
    SDL_RenderClear( graphics->canvas );
    drawField();
    for(unsigned int i=0;i<colonies.size();++i)
    {
        colonies[i]->draw();
    }
    for (unsigned int i=0;i<food.size();i++)
    {
        food[i]->draw();
    }
    SDL_RenderPresent( graphics->canvas );
}

void Scene::allFoods()
{
    for (int i=0;i<20;i++)
    {
        dynamic_cast<Food*>(food[i])->spawn();
    }

}
