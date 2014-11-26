#include "block.h"
#include "scene.h"
#include "graphics.h"
#include <cmath>
#include <algorithm>

Block::Block( std::shared_ptr<Scene> scene, int x, int y, const std::string &name) :
    mainScene(scene), x_(x), y_(y), name_( name )
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

double Block::distance2( std::weak_ptr<Block> who ) const
{
    std::shared_ptr<Block> existingWho( who );
    SDL_assert( existingWho );
    double deltaX = getX() - existingWho->getX();
    double deltaY = getY() - existingWho->getY();
    return ( ( deltaX * deltaX ) + ( deltaY * deltaY ) );
}

double Block::distance( std::weak_ptr<Block> who ) const
{
    double distanceSquared = distance2( who );
    SDL_assert( distanceSquared >= 0 );
    return sqrt( distanceSquared );
}

void Block::step(Direction where)
{
    SDL_assert( ( first <= where ) && ( where <= last ) );
    std::shared_ptr<Scene> scene( mainScene );
    SDL_assert( scene );
    switch (where){
    case up :
        y_++;
        if(y_ >= scene->fieldHeight)
            y_ -= scene->fieldHeight;
        break;
    case down :
        y_--;
        if(y_ < 0)
            y_ += scene->fieldHeight;
        break;
    case left :
        x_--;
        if(x_ < 0)
            x_ += scene->fieldWidth;
        break;
    case right :
        x_++;
        if(x_ >= scene->fieldWidth)
            x_ -= scene->fieldWidth;
        break;
    case end :
        break;
    default:
        SDL_assert( false );
        break;
    }
}

bool Block::isOn( std::weak_ptr<Block> who ) const
{
    std::shared_ptr<Block> existingWho( who );
    if( existingWho )
    {
        return ( x_ == existingWho->x_ ) && ( y_ == existingWho->y_ );
    }
    return false;
}


std::weak_ptr<Block> Block::nearest( const std::vector<std::shared_ptr<Block>>& vect )
{
    if( vect.size() == 0 )
    {
        return std::weak_ptr<Block>();
    }
    else
    {
        return *std::min_element( vect.begin(),
                                  vect.end(),
                                  [this]( std::shared_ptr<Block> left,
                                          std::shared_ptr<Block> right)
                                  {
                                      return distance2(left) < distance2(right);
                                  }
                        );
    }
}
