#include "colony.h"
#include "base.h"
#include "ant.h"

Colony::Colony(float r, float g, float b, int scoreX, int scoreY) :
    score(0.0),
    red( r ),
    green( g ),
    blue( b ),
    scorePosX( scoreX ),
    scorePosY( scoreY )
{
}

Base* Colony::nearestBase( Ant *who )
{
    Base* nearest = bases[0];
    double minDistance = who->distance( nearest );
    for(unsigned int i = 1; i < bases.size(); ++i )
    {
        double current = who->distance( bases[i] );
        if( current < minDistance)
        {
            minDistance = current;
            nearest = bases[ i ];
        }
    }
    return nearest;
}

void Colony::draw()
{
    for(unsigned int i=0;i<bases.size();++i)
    {
        bases[i]->draw();
        bases[i]->print();
    }
    for(unsigned int i=0;i<ants.size();++i)
    {
        ants[i]->draw();
    }
}
