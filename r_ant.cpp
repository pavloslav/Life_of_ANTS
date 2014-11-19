#include "r_ant.h"

R_ant::R_ant()
{
    Invent = false;
    turn = false;
    size = Ant::StartSize;
    direction = GLUT_KEY_RIGHT;
    //set_speed(25);
}
void R_ant::DrawSnake(int i)
{
    glColor3f(1.0, 0.0, 0.0);
        glRectf(r_ant[i].x * 1, r_ant[i].y * 1, (r_ant[i].x + 0.9) * 1, (r_ant[i].y + 0.9) * 1);
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
