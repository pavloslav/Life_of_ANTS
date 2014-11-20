#include "food.h"
#include <GL/glut.h>
#include "block.h"
#include "scene.h"

Food::Food() : Block( (rand()%WIDTH), (rand()%HEIGHT))
{
}


void Food::draw()
{
    glColor3f(0.0,1.0,1.0);
    glRectf(getX()*mainScene->scale,getY()*mainScene->scale,(getX()+1)*mainScene->scale,(getY()+1)*mainScene->scale);
}

void Food::spawn()
{
    setX((rand()%WIDTH));
    setY((rand()%HEIGHT));
}

