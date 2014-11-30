#include "app.h"
#include "base.h"
#include "colony.h"


Base::Base( const ModelPoint& location, const std::string& name, std::shared_ptr<Colony> col ) :
    ColonyBlock( location, name, col )
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
    points[0] = getPlace() + ModelPoint(  1,  0 );
    points[1] = getPlace() + ModelPoint(  0,  1 );
    points[2] = getPlace() + ModelPoint( -1,  0 );
    points[3] = getPlace() + ModelPoint(  0, -1 );
    points[4] = getPlace() + ModelPoint(  1, 0  );
    SDL_RenderDrawLines( graphics->renderer, points, 5 );
}

