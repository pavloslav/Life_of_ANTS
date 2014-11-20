#ifndef BLOCK_H
#define BLOCK_H

#define WIDTH 300
#define HEIGHT 150
#define BARR 50

class Scene;

class Block {
private:
    int x_;
    int y_;

public:
    static Scene *mainScene;

    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    Block( int x, int y );
    virtual void draw();
    double distance(const Block& target);

    typedef enum{ up, down, left, right, end } Direction;
    void step(Direction where);
};

#endif // BLOCK_H
