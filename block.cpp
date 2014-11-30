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

const ModelPoint &Block::getPlace()
{
    return place;
}

void Block::setPlace( const ModelPoint &p )
{
    place = p;
}

const std::string &Block::getName() const
{
    return name_;
}

void Block::setName(const std::string &newName)
{
    name_ = newName;
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
                                      return place.distance2(left->place) < place.distance2(right->place);
                                  }
                        );
    }
}
