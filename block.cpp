#include "block.h"
#include "scene.h"
#include "graphics.h"
#include <cmath>

Block::Block( int x, int y ) :
    x_(x), y_(y)
{
}

void Block::setX( int x )
{
    x_ = x;
}
int Block::getX() const
{
    return x_;
}

void Block::setY( int y )
{
    y_ = y;
}

int Block::getY() const
{
    return y_;
}
double Block::distance(Block* target) const
{
    double deltaX = getX() - target->getX();
    double deltaY = getY() - target->getY();
    double delta = ((deltaX*deltaX)+(deltaY*deltaY));

    return sqrt(delta);
}
void Block::step(Direction where)
{
    switch (where){
    case up :
        y_++;
        if(y_ >= FIELD_HEIGHT)
            y_ -= FIELD_HEIGHT;
        break;
    case down :
        y_--;
        if(y_ < 0)
            y_ += FIELD_HEIGHT;
        break;
    case left :
        x_--;
        if(x_ < 0)
            x_ += FIELD_WIDTH;
        break;
    case right :
        x_++;
        if(x_ >= FIELD_WIDTH)
            x_ -= FIELD_WIDTH;
        break;
    case end :
        break;
    }
}

bool Block::isOn( Block* target ) const
{
    return ( x_ == target->x_ ) && ( y_ == target->y_ );
}

Block* Block::nearest( const std::vector<Block*>& vect )
{
    if( vect.size() == 0 )
    {
        return NULL;
    }
    Block* nearest = vect[0];
    if( vect.size() > 1 )
    {
        double minDistance = distance( nearest );
        for(unsigned int i = 1; i < vect.size(); ++i )
        {
            double current = distance( vect[i] );
            if( current < minDistance)
            {
                minDistance = current;
                nearest = vect[ i ];
            }
        }
    }
    return nearest;
}
