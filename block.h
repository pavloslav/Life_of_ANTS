#include <vector>
#include <string>

#ifndef BLOCK_H
#define BLOCK_H

class Scene;

class Block {
public:
    static Scene *mainScene;

    Block( int x, int y, const std::string& name );
    virtual ~Block();

    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    void setXY( int x, int y );
    const std::string& getName() const;
    void setName( const std::string& newName );
    virtual void draw() = 0;
    double distance(Block* target) const;

    enum Direction{ first, up = first, down, left, right, end, last = end } ;
    void step(Direction where);
    bool isOn( Block* target ) const;
    bool isOn( Block** target,
               const std::vector<Block*> *reserve = 0 );

    Block* nearest( const std::vector<Block*>& vect );

private:
    int x_;
    int y_;
    std::string name_;
};

#endif // BLOCK_H
