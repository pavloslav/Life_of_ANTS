#include "b_base.h"
#include <GL/glut.h>
#include "scene.h"

B_base::B_base( int x, int y ): Base( x, y )
{
}

void B_base::draw() const
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(getX() + mainScene->scale, getY());
    glVertex2f(getX(), getY() + mainScene->scale);
    glVertex2f(getX() - mainScene->scale, getY());
    glVertex2f(getX(), getY() - mainScene->scale);
    glEnd();
}

void B_base::print() const
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(280,180 );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + score);
}
