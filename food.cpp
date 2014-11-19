#include "food.h"
#include <GL/glut.h>

Food::Food() : Block( (rand()%WIDTH), (rand()%HEIGHT))
{
}


void Food::draw_food()
{
    glColor3f(0.0,1.0,1.0);
    glRectf(x*mainScene->scale,y*mainScene->scale,(x+1)*mainScene->scale,(y+1)*mainScene->scale);
}

Food::spawn()
{
    setX((rand()%WIDTH));
    setY((rand()%HEIGHT));
}

