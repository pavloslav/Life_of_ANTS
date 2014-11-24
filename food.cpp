#include "food.h"
#include "block.h"
#include "scene.h"
#include "graphics.h"

Food::Food( std::shared_ptr<Scene> scene, const std::string &name ) :
    Block( scene, rand() % scene->fieldWidth, rand() % scene->fieldHeight, name ),
    label( scene->graphics, scene->graphics->smallFont, 0, 0, scene->foodColor, name )
{
    SDL_Point realPoint = mainScene->graphics->point( getX(), getY() );
    label.setXY( realPoint.x, realPoint.y - 10 );
}

Food::~Food()
{
}

void Food::draw()
{
    mainScene->graphics->setColor( mainScene->foodColor );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 1.3, 1.3 );
    SDL_RenderDrawRect( mainScene->graphics->renderer, &rect );
    label.draw();
}
