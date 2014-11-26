#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include <memory>
#include "geometry.h"

class Scene;

class Block {
public:
    Block( ModelPoint p, const std::string& name );
    virtual ~Block();

    const ModelPoint& getPlace();
    void getPlace( const ModelPoint& p );
    const std::string& getName() const;
    void setName( const std::string& newName );
    virtual void draw() = 0;
   // double distance( std::weak_ptr<Block> who ) const;
   // double distance2( std::weak_ptr<Block> who ) const;

    //enum Direction{ first, up = first, down, left, right, end, last = end } ;
    //ModelPoint Direction;
    void step( ModelPoint shift );
   // bool isOn( std::weak_ptr<Block> who ) const;

    std::weak_ptr<Block> nearest( const std::vector<std::shared_ptr<Block>>& vect );

private:
    ModelPoint place;
    std::string name_;
};

#endif // BLOCK_H
