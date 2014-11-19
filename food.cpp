#include "food.h"
#include <GL/glut.h>

Food::Food()
{
x = 1;
y = 1;
}


void Food::draw_food()
{
    glColor3f(0.0,1.0,1.0);
    glRectf(x*mainScene->scale,y*mainScene->scale,(x+1)*mainScene->scale,(y+1)*mainScene->scale);
}

void Food::spawn(){
        x = (rand()%WIDTH);
        y = (rand()%HEIGHT);
        for(int i = 0; i < 10; i++){
                if((x == mainScene->r_ant[0].x)&&(y == mainScene->r_ant[0].y))spawn();
        }
}



