#include <vector>

#ifndef BLOCK_H
#define BLOCK_H

class Scene;

class Block {
public:
    static Scene *mainScene;

    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    Block( int x, int y );
    virtual void draw() = 0;
    double distance(Block* target) const;

    enum Direction{ up, down, left, right, end } ;
    void step(Direction where);
    bool isOn( Block* target ) const;

    Block* nearest( const std::vector<Block*>& vect );

private:
    int x_;
    int y_;
};

#endif // BLOCK_H
