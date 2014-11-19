#include "block.h"
#include <GL/glut.h>
#include "scene.h"

Block::Block( )
{
    x = 1;
    y = 1;
}

void Block::draw()
{
    glColor3f(0.0,1.0,0.0);
glVertex2f(x*mainScene->scale,y*mainScene->scale);
glVertex2f(x*mainScene->scale+mainScene->scale,y*mainScene->scale);
glVertex2f(x*mainScene->scale+mainScene->scale,y*mainScene->scale+mainScene->scale);
glVertex2f(x*mainScene->scale,y*mainScene->scale+mainScene->scale);
}
