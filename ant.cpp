#include "ant.h"
#include "scene.h"
#include <GL/glut.h>

Ant::Ant( ) :
    size( 1 ),
    StartPosX ( WIDTH / 6 ),
    StartPosY ( HEIGHT / 6 ),
    StartSize( 1 )
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

        double delta=0;
        int deltaX;
        int deltaY;

        int* n=new int;
        *n=0;
        for (int i=0;i<size;++i){     //перераховує масив m[i]
            deltaX=mainScene->r_ant[j].x-mainScene->m[i]->x;
            deltaY=mainScene->r_ant[j].y-mainScene->m[i]->y;
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

            if (mainScene->r_ant[i].y<mainScene->m[*ptr]->y){// верх
                if((mainScene->rant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->rant[i]->turn))
                {
                    mainScene->rant[i]->direction = GLUT_KEY_UP;
                    mainScene->rant[i]->turn = false;
                }

            }
                if (mainScene->r_ant[i].y>mainScene->m[*ptr]->y){ //низ
                    if((mainScene->rant[i]->direction != GLUT_KEY_UP)&&(mainScene->rant[i]->turn))
                    {
                        mainScene->rant[i]->direction = GLUT_KEY_DOWN;
                        mainScene->rant[i]->turn = false;
                    }

                }
            if (mainScene->r_ant[i].x<mainScene->m[*ptr]->x){// вправо
                if((mainScene->rant[i]->direction != GLUT_KEY_LEFT)&&(mainScene->rant[i]->turn))
                {
                    mainScene->rant[i]->direction = GLUT_KEY_RIGHT;
                    mainScene->rant[i]->turn = false;
                }

            }
                if (mainScene->r_ant[i].x>mainScene->m[*ptr]->x){//ліво
                    if((mainScene->rant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->rant[i]->turn))
                    {
                        mainScene->rant[i]->direction = GLUT_KEY_LEFT;
                        mainScene->rant[i]->turn = false;
                    }

                }
       }


            if(targ[*ptr]>=50)
            {

                x = (rand()% 3);
                        if(x<2){
                mainScene->rant[i]->direction = GLUT_KEY_END;
                mainScene->rant[i]->turn = false;
                        }
                        else
                            go_home(i);
            }

}

void Ant::eat(int j){
    for(int i=0;i<20;++i)
    {
        if((mainScene->r_ant[j].x == mainScene->m[i]->x)&&(mainScene->r_ant[j].y == mainScene->m[i]->y)){
            mainScene->rant[j]->Invent=true;

        mainScene->m[i]->spawn();
        }
}
}




void Ant::chek(int i)
{
    if (mainScene->rant[i]->Invent==true){

        mainScene->rant[i]->go_home(i);
    }
    if (mainScene->rant[i]->Invent==false)
        search(i);

}






void Ant::go_home(int i)
{
        if (mainScene->r_ant[i].y<mainScene->base[0].y){// верх
            if((mainScene->rant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->rant[i]->turn))
            {
                mainScene->rant[i]->direction = GLUT_KEY_UP;
                mainScene->rant[i]->turn = false;
            }
        }
            if (mainScene->r_ant[i].y>mainScene->base[0].y){ //низ
                if((mainScene->rant[i]->direction != GLUT_KEY_UP)&&(mainScene->rant[i]->turn))
                {
                   mainScene->rant[i]->direction = GLUT_KEY_DOWN;
                   mainScene->rant[i]->turn = false;
                }
            }
        if (mainScene->r_ant[i].x<mainScene->base[0].x){// вправо
            if((mainScene->rant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->rant[i]->turn))
            {
                mainScene->rant[i]->direction = GLUT_KEY_RIGHT;
                mainScene->rant[i]->turn = false;
            }
        }

            if (mainScene->r_ant[i].x>mainScene->base[0].x){//ліво
                if((mainScene->rant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->rant[i]->turn))
                {
                    mainScene->rant[i]->direction = GLUT_KEY_LEFT;
                    mainScene->rant[i]->turn = false;


            }


    }
}
void Ant::eject(int i)
{

    if((mainScene->rant[i]->Invent)&&((mainScene->r_ant[i].x == mainScene->base[0].x)&&(mainScene->r_ant[i].y == mainScene->base[0].y)))
    {
       mainScene->rant[i]->Invent=false;
        mainScene->r_base.Score++;

}
}
