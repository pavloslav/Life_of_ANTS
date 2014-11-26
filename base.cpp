#include "app.h"
#include "base.h"
#include "colony.h"


Base::Base( int x, int y, const std::string& name, std::shared_ptr<Colony> col ) :
    ColonyBlock( x, y, name, col )
{
}

Base::~Base()
{
}

void Base::draw()
{
    const std::shared_ptr<Graphics> &graphics = App::getApp()->getGraphics();
    graphics->setColor( getColony()->color );
    SDL_Point points[5];
    points[0] = Graphics::point( getX() + 1, getY()     );
    points[1] = Graphics::point( getX(),     getY() + 1 );
    points[2] = Graphics::point( getX() - 1, getY()     );
    points[3] = Graphics::point( getX(),     getY() - 1 );
    points[4] = points[0];
    SDL_RenderDrawLines( graphics->renderer, points, 5 );
}

