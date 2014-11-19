#include "ant.h"
#include "scene.h"
#include <GL/glut.h>

Ant::Ant( ) :
    speed( 1 ),
    live( 100 ),
    speedAtack( 1 ),
    size( 1 ),
    turn( true ),
    invent( true ),
    startPosX ( WIDTH / 6 ),
    startPosY ( HEIGHT / 6 ),
    startSize( 1 ),
    direction( GLUT_KEY_UP )
{
}

void Ant::setSpeed(double sp)
{
    speed=sp;
}
double Ant::getSpeed() const
{
    return speed;
}

void Ant::setLive(double lv)
{
    live = lv;
}

double Ant::getLive() const
{
    return live;
}

void Ant::setSpeedatack(double spa)
{
    speedAtack = spa;
}

double Ant::getSpeedatack() const
{
    return speedAtack;
}


void Ant::search(int j)
{
        double size = 20;
        double targ[20];

        int* n=new int;
        *n=0;
        for (int i=0;i<size;++i){     //перераховує масив m[i]
            double deltaX=mainScene->r_ant[j].x-mainScene->m[i]->x,
                   deltaY=mainScene->r_ant[j].y-mainScene->m[i]->y;
            double delta=((deltaX*deltaX)+(deltaY*deltaY));

            targ[i] = sqrt(delta);
            if(targ[i]<=targ[*n]){
                *n=i;
            }



        }
        navig(targ,n,j );
}




void Ant::navig(double* targ, int *ptr, int i )
{
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

                        if((rand()% 3)<2){
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
            mainScene->rant[j]->invent=true;

        mainScene->m[i]->spawn();
        }
}
}




void Ant::chek(int i)
{
    if (mainScene->rant[i]->invent==true){

        mainScene->rant[i]->go_home(i);
    }
    if (mainScene->rant[i]->invent==false)
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

    if((mainScene->rant[i]->invent)&&((mainScene->r_ant[i].x == mainScene->base[0].x)&&(mainScene->r_ant[i].y == mainScene->base[0].y)))
    {
       mainScene->rant[i]->invent=false;
        mainScene->r_base.score++;

}
}
