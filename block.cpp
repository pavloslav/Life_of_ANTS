#include "block.h"
#include <GL/glut.h>
#include "scene.h"
#include <cmath>

Block::Block( int x, int y ) :
    x_(x), y_(y)
{
}

void Block::draw()
{
    glColor3f(0.0,1.0,0.0);
    glVertex2f(x_*mainScene->scale,y_*mainScene->scale);
    glVertex2f(x_*mainScene->scale+mainScene->scale,y_*mainScene->scale);
    glVertex2f(x_*mainScene->scale+mainScene->scale,y_*mainScene->scale+mainScene->scale);
    glVertex2f(x_*mainScene->scale,y_*mainScene->scale+mainScene->scale);
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
double Block::distance(const Block& target)
{
    double deltaX = getX() - target.getX();
    double deltaY = getY() - target.getY();
    double delta = ((deltaX*deltaX)+(deltaY*deltaY));

    return sqrt(delta);
}
void Block::step(Direction where)
{
    switch (where){
    case up :
        y_++;
        break;
    case down :
        y_--;
        break;
    case left :
        x_--;
        break;
    case right :
        x_++;
        break;
    case end :
        break;
    }

    if(x_ < 0)
        x_ += WIDTH;
    if(x_ >= WIDTH)
        x_ -= WIDTH;
    if(y_ < 0)
        y_ += HEIGHT;
    if(y_ >= HEIGHT)
        y_ -= HEIGHT;
}
