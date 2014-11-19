#include "r_base.h"
#include <GL/glut.h>
#include "scene.h"

R_base::R_base( )
{
}

void R_base::draw() const
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f( mainScene->base[0].x + mainScene->scale, mainScene->base[0].y);
    glVertex2f( mainScene->base[0].x, mainScene->base[0].y + mainScene->scale);
    glVertex2f( mainScene->base[0].x - mainScene->scale, mainScene->base[0].y);
    glVertex2f( mainScene->base[0].x, mainScene->base[0].y - mainScene->scale);
    glEnd();
}
void R_base::print() const
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(15,180 );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + score);

    }
