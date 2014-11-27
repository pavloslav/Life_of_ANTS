#include "food.h"
#include "app.h"
#include "graphics.h"
#include "scene.h"
#include "label.h"

Food::Food( int x, int y, const std::string &name ) :
    Block( x, y, name ),
    label( App::getApp()->getGraphics()->smallFont,
           0,
           0,
           App::getApp()->getScene()->foodColor,
           name )
{
    SDL_Point realPoint = Graphics::point( getX(), getY() );
    label.setXY( realPoint.x, realPoint.y - 10 );
}

Food::~Food()
{
}

void Food::draw()
{
    const std::shared_ptr<Graphics> &graphics = App::getApp()->getGraphics();
    graphics->setColor( App::getApp()->getScene()->foodColor );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 1.3, 1.3 );
    SDL_RenderDrawRect( graphics->renderer, &rect );
    label.draw();
}
