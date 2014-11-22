#include "base.h"
#include "colony.h"
#include "scene.h"

Base::Base( int x, int y, Colony *col ) :
    ColonyBlock( x, y, col ),
    size( 1 ),
    startPosX( x ),
    startPosY( y )
{
    getColony()->bases.push_back( this );
}

void Base::draw()
{
    getColony()->SetSDLColor( mainScene->graphics->canvas );
    SDL_Point points[5];
    points[0] = Graphics::point( getX() + 1, getY()     );
    points[1] = Graphics::point( getX(),     getY() + 1 );
    points[2] = Graphics::point( getX() - 1, getY()     );
    points[3] = Graphics::point( getX(),     getY() - 1 );
    points[4] = points[0];
    SDL_RenderDrawLines( mainScene->graphics->canvas, points, 5 );
}

