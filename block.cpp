#include "block.h"
#include <GL/glut.h>
#include "scene.h"
#include <cmath>

Block::Block( int x_, int y_ ) :
    x(_x), y(_y)
{
}

void Block::draw()
{
    glColor3f(0.0,1.0,0.0);
    glVertex2f(x*mainScene->scale,y*mainScene->scale);
    glVertex2f(x*mainScene->scale+mainScene->scale,y*mainScene->scale);
    glVertex2f(x*mainScene->scale+mainScene->scale,y*mainScene->scale+mainScene->scale);
    glVertex2f(x*mainScene->scale,y*mainScene->scale+mainScene->scale);
}
void Block::setX( int x )
{
    x_ = x;
}
int Block::getX() const
{
    return x;
}

void Block::setY( int y )
{
    y_ = y;
}

int Block::getY() const
{
    return y;
}
double Block::distance(const Block& target)
{
    double deltaX = getX() - target.getX();
    double deltaY = getY() - target.getY();
    double delta = ((deltaX*deltaX)+(deltaY*deltaY));

    return sqrt(delta);
}
void Block::move(direction where)
{
    switch (where){
    case up :
        y++;
        break;
    case down :
        y--;
        break;
    case left :
        x--;
        break;
    case right :
        x++;
        break;
    case end :
        break;
    }

    if(mainScene->bant[i]->getX() < 0)mainScene->bant[i]->getX() += WIDTH;
    if(mainScene->bant[i]->getX() >= WIDTH)mainScene->bant[i]->getX() -= WIDTH;
    if(mainScene->bant[i]->getY() < 0)mainScene->bant[i]->getY() += HEIGHT;
    if(mainScene->bant[i]->getY() >= HEIGHT)mainScene->bant[i]->getY() -= HEIGHT;
}
