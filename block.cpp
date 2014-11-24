#include "block.h"
#include "scene.h"
#include "graphics.h"
#include <cmath>
#include <algorithm>

Block::Block(int x, int y, const std::string &name) :
    x_(x), y_(y), name_( name )
{

}

Block::~Block()
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

void Block::setXY(int x, int y)
{
    x_ = x;
    y_ = y;
}

const std::string &Block::getName() const
{
    return name_;
}

void Block::setName(const std::string &newName)
{
    name_ = newName;
}

double Block::distance(Block* target) const
{
    double deltaX = getX() - target->getX();
    double deltaY = getY() - target->getY();
    double delta = ((deltaX*deltaX)+(deltaY*deltaY));
    SDL_assert( delta>= 0);
    return sqrt(delta);
}
void Block::step(Direction where)
{
    SDL_assert( ( first <= where ) && ( where <= last ) );
    switch (where){
    case up :
        y_++;
        if(y_ >= mainScene->fieldHeight)
            y_ -= mainScene->fieldHeight;
        break;
    case down :
        y_--;
        if(y_ < 0)
            y_ += mainScene->fieldHeight;
        break;
    case left :
        x_--;
        if(x_ < 0)
            x_ += mainScene->fieldWidth;
        break;
    case right :
        x_++;
        if(x_ >= mainScene->fieldWidth)
            x_ -= mainScene->fieldWidth;
        break;
    case end :
        break;
    default:
        SDL_assert( false );
        break;
    }
}

bool Block::isOn( Block** target,
                  const std::vector<Block*> *reserve )
{
    SDL_assert( target != NULL );
    SDL_assert( reserve != NULL );
    if( *target == NULL )
        return false;
    std::vector<Block*>::const_iterator existingTarget
                                    = std::find( reserve->begin(),
                                                 reserve->end(),
                                                 *target );
    if( existingTarget == reserve->end() )
        return false;
    if( isOn( *existingTarget ) )
        return true;
    return false;
}

bool Block::isOn( Block* target ) const
{
    if( target == NULL )
        return false;
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
