#include <vector>

#ifndef BLOCK_H
#define BLOCK_H

#define WIDTH 300
#define HEIGHT 150
#define BARR 50

class Scene;

class Block {
public:
    static Scene *mainScene;

    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    Block( int x, int y );
    virtual void draw() const;
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
