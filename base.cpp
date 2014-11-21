#include "base.h"
#include "colony.h"
#include "scene.h"
#include <GL/glut.h>

Base::Base( int x, int y, Colony *col ) :
    ColonyBlock( x, y, col ),
    size( 1 ),
    startPosX( x ),
    startPosY( y )
{
    getColony()->bases.push_back( this );
}

void Base::draw() const
{
    glColor3f( getColony()->red, getColony()->green, getColony()->blue );
    glBegin(GL_POLYGON);
    glVertex2f( getX() + mainScene->scale, getY());
    glVertex2f( getX(), getY() + mainScene->scale);
    glVertex2f( getX() - mainScene->scale, getY());
    glVertex2f( getX(), getY() - mainScene->scale);
    glEnd();
    print();
}

void Base::print() const
{
    glColor3f( getColony()->red, getColony()->green, getColony()->blue );
    glRasterPos2f( getColony()->scorePosX, getColony()->scorePosY );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + getColony()->score);
}
