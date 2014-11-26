#include "colony.h"

#include <sstream>
#include <algorithm>

#include "ant.h"
#include "scene.h"
#include "base.h"

Colony::Colony(std::shared_ptr<Scene> scene, Color col, int scoreX, int scoreY ) :
    mainScene( scene ),
    score( 0.0 ),
    color( col ),
    scorePosX( scoreX ),
    scorePosY( scoreY ),
    label( mainScene->graphics, mainScene->graphics->font, scoreX, scoreY, col )
{
    SDL_assert( mainScene );
}

Colony::~Colony()
{
}

void Colony::draw()
{
    for( auto base : bases )
    {
        base->draw();
    }
    for( auto ant : ants )
    {
        ant->draw();
    }
    ( label.setText("Lives: ") << score ).draw();
}

void Colony::action()
{
    for(auto ant : ants )
        ant->action();
}

void Colony::createBase(int x, int y, const std::string &name)
{
    bases.push_back( std::make_shared<Base>( mainScene, x, y, name, shared_from_this() ) );
}

void Colony::createAnt(int x, int y, const std::string &name)
{
    ants.push_back( std::make_shared<Ant>( mainScene, x, y, name, shared_from_this() ) );
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
