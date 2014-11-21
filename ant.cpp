#include "ant.h"
#include "scene.h"
#include "food.h"
#include "base.h"
#include "colony.h"
#include "colonyblock.h"

#include <cstdlib>
#include <GL/glut.h>

Ant::Ant( int x, int y, Colony *col ) : ColonyBlock( x, y, col ),
    speed( 1 ),
    live( 100 ),
    speedAtack( 1 ),
    size( 1 ),
    turn( false ),
    isCarringFood( false ),
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

void Ant::search()
{
    int size = 20;
    int minDistance = distance( mainScene->food[0] );
    Food *closestFood = mainScene->food[0];
    for (int i=1;i<size;++i){     //перераховує масив food[i]
        double currentDistance = distance(*mainScene->food[i]);
        if(minDistance>currentDistance){
            minDistance = currentDistance;
            closestFood = mainScene->food[i];
        }
    }
    navig( minDistance, closestFood );
}


void Ant::goTo(Block *target)
{
    if (getY()<target->getY()){// верх
        if((direction != Block::down)&&(turn))
        {
            direction = Block::up;
            turn = false;
        }
    }
    if (getY()>target->getY()){ //низ
        if((direction != Block::up)&&(turn))
        {
            direction = Block::down;
            turn = false;
        }
    }
    if (getX()<target->getX()){// вправо
        if((direction != Block::left)&&(turn))
        {
            direction = Block::right;
            turn = false;
        }
    }
    if (getX()>target->getX()){//ліво
        if((direction != Block::right)&&(turn))
        {
            direction = Block::left;
            turn = false;
        }

    }
}

void Ant::navig( double distance, Food *target )
{
    if(distance<=50)
    {
        goTo(target);
    }
    if(distance>=50)
    {
        if((rand()% 3)<2)
        {
            direction = Block::end;
            turn = false;
        }
        
    }
    goTo(target);
}

void Ant::eat()
{
    for(int i=0;i<20;++i)
    {
        if( isOn( mainScene->food[ i ] ) )
        {
            isCarringFood=true;
            mainScene->food[i]->spawn();
        }
    }
}

void Ant::chek()
{
    if (isCarringFood)
    {
        goHome();
    }
    else
    {
        search();
    }
}

void Ant::goHome()
{
    //goTo( home_ );
    goTo( getColony()->nearestBase( this ) );
}

void Ant::eject()
{
    Base *home = getColony()->nearestBase( this );
    if( ( isCarringFood )&&( isOn( home ) ) )
    {
        isCarringFood=false;
        getColony()->score++;
    }
}

void Ant::action()
{
    turn = true;
    chek();
    step(direction);
    eat();
    eject();
}

void Ant::draw()
{
    glColor3f( getColony()->red, getColony()->green, getColony()->blue );
    glRectf(getX() * 1, getY() * 1, (getX() + 0.9) * 1, (getY() + 0.9) * 1);
}
