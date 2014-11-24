#include "food.h"
#include "block.h"
#include "scene.h"
#include "graphics.h"

Food::Food(const std::string &name ) :
    Block( rand() % mainScene->fieldWidth, rand() % mainScene->fieldHeight, name ),
    label( mainScene->graphics, mainScene->graphics->smallFont, 0, 0, mainScene->foodColor, name )
{
    SDL_Point realPoint = mainScene->graphics->point( getX(), getY() );
    label.setXY( realPoint.x, realPoint.y - 10 );
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
    label.draw();
}
