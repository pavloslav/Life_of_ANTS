#include "ant.h"
#include <GL/glut.h>

Ant::Ant( Scene* scene ) :
    mainScene( scene ),
    size( 1 ),
    StartSize( 1 ),
    StartPosX ( WIDTH / 6 ),
    StartPosY ( HEIGHT / 6 )
{
}

void Ant::set_speed(double sp)
{
    Speed=sp;
}
double Ant::get_speed()
{
    return Speed;
}

void Ant::set_live(double lv)
{
    Live = lv;
}

double Ant::get_live()
{
    return Live;
}

void Ant::set_speedatack(double spa)
{
    SpeedAtack = spa;
}

double Ant::get_speedatack()
{
    return SpeedAtack;
}


void Ant::search(int j)
{
        double size = 20;
        double targ[20];
        double bufer=0;

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

void B_ant::search(int j)
{
        double size = 20;
        double targ[20];
        double bufer=0;

        double delta=0;
        int deltaX;
        int deltaY;

        int* n=new int;
        *n=0;
        for (int i=0;i<size;++i){     //перераховує масив m[i]
            deltaX=b_ant[j].x-m[i]->x;
            deltaY=b_ant[j].y-m[i]->y;
            delta=((deltaX*deltaX)+(deltaY*deltaY));

            targ[i] = sqrt(delta);
            if(targ[i]<=targ[*n]){
                *n=i;
            }



        }
        navig(targ,n,j );
}


void Ant::navig(double* targ, int *ptr, int i )
{
    int x;
       if(targ[*ptr]<=50)
    {

            if (r_ant[i].y<m[*ptr]->y){// верх
                if((rant[i]->direction != GLUT_KEY_DOWN)&&(rant[i]->turn))
                {
                    rant[i]->direction = GLUT_KEY_UP;
                    rant[i]->turn = false;
                }

            }
                if (r_ant[i].y>m[*ptr]->y){ //низ
                    if((rant[i]->direction != GLUT_KEY_UP)&&(rant[i]->turn))
                    {
                        rant[i]->direction = GLUT_KEY_DOWN;
                        rant[i]->turn = false;
                    }

                }
            if (r_ant[i].x<m[*ptr]->x){// вправо
                if((rant[i]->direction != GLUT_KEY_LEFT)&&(rant[i]->turn))
                {
                    rant[i]->direction = GLUT_KEY_RIGHT;
                    rant[i]->turn = false;
                }

            }
                if (r_ant[i].x>m[*ptr]->x){//ліво
                    if((rant[i]->direction != GLUT_KEY_RIGHT)&&(rant[i]->turn))
                    {
                        rant[i]->direction = GLUT_KEY_LEFT;
                        rant[i]->turn = false;
                    }

                }
       }


            if(targ[*ptr]>=50)
            {

                x = (rand()% 3);
                        if(x<2){
                rant[i]->direction = GLUT_KEY_END;
                rant[i]->turn = false;
                        }
                        else
                            go_home(i);
            }

}





