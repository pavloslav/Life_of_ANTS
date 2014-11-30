#include "food.h"
#include "app.h"
#include "graphics.h"
#include "scene.h"
#include "label.h"

Food::Food( const ModelPoint& location, const std::string &name ) :
    Block( location, name ),
    label( App::getApp()->getGraphics()->smallFont,
           location,
           App::getApp()->getScene()->foodColor,
           name )
{
}

Food::~Food()
{
}

void Food::draw()
{
    const std::shared_ptr<Graphics> &graphics = App::getApp()->getGraphics();
    graphics->setColor( App::getApp()->getScene()->foodColor );
    SDL_Rect rect = ScreenRectangle( getPlace(), ModelPoint(1.3, 1.3) );
    SDL_RenderDrawRect( graphics->renderer, &rect );
    label.draw();
}
