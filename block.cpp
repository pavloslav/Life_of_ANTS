#include "block.h"
//#include "scene.h"
#include "app.h"
#include "graphics.h"
#include <cmath>
#include <algorithm>

Block::Block(ModelPoint p, const std::string &name ) :
    place( p ), name_( name )
{
}

Block::~Block()
{
}

const std::string &Block::getName() const
{
    return name_;
}

void Block::setName(const std::string &newName)
{
    name_ = newName;
}

/*double Block::distance2( std::weak_ptr<Block> who ) const
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
}*/

void Block::step( ModelPoint shift )
{
    place += shift;
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
                                  [this]( const std::shared_ptr<Block>& left,
                                          const std::shared_ptr<Block>& right)
                                  {
                                      return place->distance2(left->place) < place->distance2(right->place);
                                  }
                        );
    }
}
