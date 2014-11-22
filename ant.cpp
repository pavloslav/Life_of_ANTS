#include "ant.h"
#include "scene.h"

#include <cstdlib>

Ant::Ant( int x, int y, Colony *col ) : ColonyBlock( x, y, col ),
    speed( 1 ),
    live( 100 ),
    speedAtack( 1 ),
    size( 1 ),
    startPosX ( WIDTH / 6 ),
    startPosY ( HEIGHT / 6 ),
    startSize( 1 ),
    direction( right ),
    state( idle ),
    target( NULL )
{
    getColony()->ants.push_back( this );
}

void Ant::setSpeed(double sp)
{
    speed=sp;
}
double Ant::getSpeed() const
{
    return speed;
}

void Ant::setLive(double lv)
{
    live = lv;
}

double Ant::getLive() const
{
    return live;
}

void Ant::setSpeedatack(double spa)
{
    speedAtack = spa;
}

double Ant::getSpeedatack() const
{
    return speedAtack;
}


void Ant::turnTo(Block *target)
{
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
        if( (rand()% 10)==0 )//раз на 10 кроків "забуваємо", що робили, щоб перевірити, де їжа
        {
            state = idle;
        }
        else
        {
            if( isOn(target) )
            {
                dynamic_cast<Food*>(target)->spawn();
                target = nearest( getColony()->bases );
                state = carringFoodHome;
            }
        }
        break;

    case carringFoodHome :
        if( isOn(target) )
        {
            getColony()->score++;
            state = idle;
            target = NULL;
        }
        break;

    }
    if(target)
        turnTo( target );
    step(direction);
}

void Ant::draw()
{
    getColony()->SetSDLColor( mainScene->graphics->canvas );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 0.9, 0.9 );
    SDL_RenderDrawRect( mainScene->graphics->canvas, &rect );
}
