#include "ant.h"
#include "scene.h"

#include <cstdlib>
#include <algorithm>

Ant::Ant( int x, int y, Colony *col ) :
    ColonyBlock( x, y, col ),
    direction( right ),
    state( idle ),
    target( NULL )
{
    SDL_assert_release( col != NULL );
    getColony()->ants.push_back( this );
}

Ant::~Ant()
{
    getColony()->forgetAnt( this );
}

void Ant::turnTo(Block *target)
{
    SDL_assert_release( target != NULL );
    if ( (getY()<target->getY() ) && ( direction != Block::down ) )
    {
        direction = Block::up;
    }
    else if ( (getY()>target->getY()) && (direction != Block::up) )
    {
        direction = Block::down;
    }
    else if ( (getX()<target->getX()) && (direction != Block::left) )
    {
        direction = Block::right;
    }
    else if ( (getX()>target->getX()) && (direction != Block::right) )
    {
        direction = Block::left;
    }
}

void Ant::action()
{   
    switch( state )
    {
    case idle :
        target = nearest( mainScene->food );
        if( distance(target) < 50 )
            state = goingToFood;
        else
            target = NULL;
        break;

    case goingToFood :
        if( (rand()% 10) == 0 )//раз на 10 кроків "забуваємо", що робили, щоб перевірити, де їжа
        {
            state = idle;
            target = NULL;
        }
        else
        {
            if( isOn( &target, &mainScene->food ) )
            {
                delete target;
                target = nearest( getColony()->bases );
                state = carringFoodHome;
            }
        }
        break;

    case carringFoodHome :
        if( isOn( &target, &getColony()->bases ) )
        {
            getColony()->score++;
            state = idle;
            target = NULL;
        }
        break;
    default:
        SDL_assert_release( false );
        break;
    }
    if(target)
        turnTo( target );
    step(direction);
}

void Ant::draw()
{
    mainScene->graphics->setColor( getColony()->color );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 0.9, 0.9 );
    SDL_RenderDrawRect( mainScene->graphics->renderer, &rect );
}
