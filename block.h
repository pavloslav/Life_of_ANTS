#ifndef BLOCK_H
#define BLOCK_H

class Scene;

class Block {
private:
    int x_;
    int y_;

public:
    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    static Scene *mainScene;
    Block( int x = 0, int y = 0);
    virtual void draw();
    double distance(const Block& target);

    enum{ up, down, left, right, end } direction;
    void move(direction where);
};

#endif // BLOCK_H
