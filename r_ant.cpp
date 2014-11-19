#include "r_ant.h"
#include <GL/glut.h>
#include "scene.h"

R_ant::R_ant( int x, int y ) : Ant( x, y )
{
}

void R_ant::drawSnake(int i)
{
    glColor3f(1.0, 0.0, 0.0);
        glRectf(mainScene->r_ant[i].x * 1, mainScene->r_ant[i].y * 1, (mainScene->r_ant[i].x + 0.9) * 1, (mainScene->r_ant[i].y + 0.9) * 1);
}
/*
void R_ant::search(int j)
{
        double size = 20;
        double targ[20];
        //double bufer=0;

        double delta=0;
        int deltaX;
        int deltaY;

        int* n=new int;
        *n=0;
        for (int i=0;i<size;++i){     //перераховує масив m[i]
            deltaX=r_ant[j].x-m[i]->x;
            deltaY=r_ant[j].y-m[i]->y;
            delta=((deltaX*deltaX)+(deltaY*deltaY));

            targ[i] = sqrt(delta);
            if(targ[i]<=targ[*n]){
                *n=i;
            }



        }
        navig(targ,n,j );
}


*/
void R_ant::move(int i){
        for(int j = 1; j > 0; j--){
                mainScene->r_ant[j].x = mainScene->r_ant[j-1].x;
                mainScene->r_ant[j].y = mainScene->r_ant[j-1].y;
        }
            switch (direction){
            case GLUT_KEY_UP :
                    mainScene->r_ant[i].y++;
                    break;
            case GLUT_KEY_DOWN :
                    mainScene->r_ant[i].y--;
                    break;
            case GLUT_KEY_LEFT :
                mainScene->r_ant[i].x--;
                    break;
            case GLUT_KEY_RIGHT :
                   mainScene->r_ant[i].x++;
                    break;
            case GLUT_KEY_END :
                    break;

        }

        if(mainScene->r_ant[i].x < 0)mainScene->r_ant[i].x += WIDTH;
        if(mainScene->r_ant[i].x >= WIDTH)mainScene->r_ant[i].x -= WIDTH;
        if(mainScene->r_ant[i].y < 0)mainScene->r_ant[i].y += HEIGHT;
        if(mainScene->r_ant[i].y >= HEIGHT)mainScene->r_ant[i].y -= HEIGHT;
}
