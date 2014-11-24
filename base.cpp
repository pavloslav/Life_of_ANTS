#include "base.h"
#include "colony.h"
#include "scene.h"

Base::Base( std::shared_ptr<Scene> scene, int x, int y, const std::string& name, std::shared_ptr<Colony> col ) :
    ColonyBlock( scene, x, y, name, col )
{
}

Base::~Base()
{
}

void Base::draw()
{
    mainScene->graphics->setColor( getColony()->color );
    SDL_Point points[5];
    points[0] = Graphics::point( getX() + 1, getY()     );
    points[1] = Graphics::point( getX(),     getY() + 1 );
    points[2] = Graphics::point( getX() - 1, getY()     );
    points[3] = Graphics::point( getX(),     getY() - 1 );
    points[4] = points[0];
    SDL_RenderDrawLines( mainScene->graphics->renderer, points, 5 );
}

