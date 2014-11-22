#include "food.h"
#include "block.h"
#include "scene.h"
#include "graphics.h"

Food::Food() :
    Block( rand() % mainScene->fieldWidth, rand() % mainScene->fieldHeight )
{
    mainScene->food.push_back( this );
}

Food::~Food()
{
    mainScene->forgetFood( this );
}

void Food::draw()
{
    mainScene->graphics->setColor( mainScene->foodColor );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 1.3, 1.3 );
    SDL_RenderDrawRect( mainScene->graphics->renderer, &rect );
}
