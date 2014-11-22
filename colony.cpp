#include "colony.h"

#include <sstream>
#include <algorithm>

#include "ant.h"
#include "scene.h"
#include "base.h"

Colony::Colony( Scene * scene, Color col, int scoreX, int scoreY ) :
    mainScene( scene ),
    score( 0.0 ),
    color( col ),
    scorePosX( scoreX ),
    scorePosY( scoreY )
{
    SDL_assert_release( mainScene != NULL );
    mainScene->colonies.push_back( this );
}

Colony::~Colony()
{
    for(int i = ants.size() - 1; i >= 0; --i)
    {
        delete ants[i];
    }
    SDL_assert_release( ants.size() == 0 );
    for(int i = bases.size() - 1; i >= 0; --i)
    {
        delete bases[i];
    }
    SDL_assert_release( bases.size() == 0 );
    mainScene->forgetColony( this );
}

void Colony::draw()
{
    for(unsigned int i=0;i<bases.size();++i)
    {
        bases[i]->draw();
    }
    for(unsigned int i=0;i<ants.size();++i)
    {
        ants[i]->draw();
    }
    print();
}

void Colony::print()
{
    mainScene->graphics->setColor( color );
    std::stringstream ss;
    ss << score;
    mainScene->graphics->outText( scorePosX, scorePosY, ss.str().c_str(), color );
}

void Colony::forgetBase(Block *what)
{
    SDL_assert_release( what != NULL );
    bases.erase( std::remove( bases.begin(), bases.end(), what ), bases.end() );
}

void Colony::forgetAnt(Block *what)
{
    SDL_assert_release( what != NULL );
    ants.erase( std::remove( ants.begin(), ants.end(), what ), ants.end() );
}
