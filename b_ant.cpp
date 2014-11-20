#include "b_ant.h"
#include <GL/glut.h>
#include "scene.h"

B_ant::B_ant( int x, int y, Base *base ) : Ant( x, y, base )
{
}


void B_ant::drawSnake()
{
    glColor3f(0.0, 0.0, 0.0);
    glRectf(getX() * 1, getY() * 1, (getX() + 0.9) * 1, (getY() + 0.9) * 1);
}

void B_ant::move(){
    for(int j = 1; j > 0; j--){
        mainScene->bant[j]->setX( mainScene->bant[j-1]->getX() );
        mainScene->bant[j]->setY( mainScene->bant[j-1]->getY() );
    }
    step(direction);
}

