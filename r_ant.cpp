#include "r_ant.h"
#include <GL/glut.h>
#include "scene.h"

R_ant::R_ant( int x, int y, Base *base ) : Ant( x, y, base )
{
}

void R_ant::drawSnake()
{
    glColor3f(1.0, 0.0, 0.0);
    glRectf(getX() * 1, getY() * 1, (getX() + 0.9) * 1, (getY() + 0.9) * 1);
}

void R_ant::move(){
    for(int j = 1; j > 0; j--){
        mainScene->rant[j]->setX( mainScene->rant[j-1]->getX() );
        mainScene->rant[j]->setY( mainScene->rant[j-1]->getY() );
    }
    step(direction);
}
