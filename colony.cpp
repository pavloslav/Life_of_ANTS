#include "colony.h"

#include <sstream>
#include <algorithm>

#include "ant.h"
#include "scene.h"
#include "base.h"
#include "app.h"

Colony::Colony(std::shared_ptr<Scene> scene, Color col, const ScreenPoint &scoreLocation) :
    mainScene( scene ),
    score( 0.0 ),
    color( col ),
    label( App::getApp()->getGraphics()->font, scoreLocation, col )
{
    SDL_assert( mainScene );
}

Colony::~Colony()
{
}

void Colony::draw()
{
    for( auto &base : bases )
    {
        base->draw();
    }
    for( auto &ant : ants )
    {
        ant->draw();
    }
    ( label.setText("Lives: ") << score ).draw();
}

void Colony::action()
{
    for( auto &ant : ants )
        ant->action();
}

std::shared_ptr<Block> Colony::createBase( const ModelPoint &location, const std::string &name )
{
    auto base = std::make_shared<Base>( location, name, shared_from_this() );
    bases.push_back( base );
    return base;
}

std::shared_ptr<Block> Colony::createAnt( const ModelPoint &location, const std::string &name)
{
    auto ant = std::make_shared<Ant>( location, name, shared_from_this() );
    ants.push_back( ant );
    return ant;
}

void Colony::forgetBase( std::weak_ptr<Block> what )
{
    std::shared_ptr<Block> existingWhat( what.lock() );
    if( existingWhat )
    {
        bases.erase( std::remove( bases.begin(), bases.end(), existingWhat ), bases.end() );
    }
}

void Colony::forgetAnt(std::weak_ptr<Block> what)
{
    std::shared_ptr<Block> existingWhat( what.lock() );
    if( existingWhat )
    {
        ants.erase( std::remove( ants.begin(), ants.end(), existingWhat ), ants.end() );
    }
}
