#include <vector>
#include <string>
#include <memory>

#ifndef BLOCK_H
#define BLOCK_H

class Scene;

class Block {
public:
    Block( std::shared_ptr<Scene> scene, int x, int y, const std::string& name );
    virtual ~Block();

    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    void setXY( int x, int y );
    const std::string& getName() const;
    void setName( const std::string& newName );
    virtual void draw() = 0;
    double distance( std::weak_ptr<Block> who ) const;
    double distance2( std::weak_ptr<Block> who ) const;

    enum Direction{ first, up = first, down, left, right, end, last = end } ;
    void step(Direction where);
    bool isOn( std::weak_ptr<Block> who ) const;

    std::weak_ptr<Block> nearest( const std::vector<std::shared_ptr<Block>>& vect );

    std::shared_ptr<Scene> mainScene;
private:
    int x_;
    int y_;
    std::string name_;
};

#endif // BLOCK_H
