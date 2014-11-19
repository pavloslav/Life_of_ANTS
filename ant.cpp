#include "ant.h"
#include "scene.h"
#include <GL/glut.h>

Ant::Ant( int x, int y ) : Block( x, y ),
    speed( 1 ),
    live( 100 ),
    speedAtack( 1 ),
    size( 1 ),
    turn( false ),
    invent( false ),
    startPosX ( WIDTH / 6 ),
    startPosY ( HEIGHT / 6 ),
    startSize( 1 ),
    direction( GLUT_KEY_RIGHT )
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

        int n = 0;
        for (int i=0;i<size;++i){     //перераховує масив food[i]
            targ[i] = mainScene->rant[j]->distance(*mainScene->food[i]);
            if(targ[i]<=targ[n]){
                n=i;
            }



        }
        navig(targ,&n,j );
}




void Ant::navig(double* targ, int *ptr, int i )
{
       if(targ[*ptr]<=50)
    {

            if (mainScene->rant[i]->getY()<mainScene->food[*ptr]->getY()){// верх
                if((mainScene->rant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->rant[i]->turn))
                {
                    mainScene->rant[i]->direction = GLUT_KEY_UP;
                    mainScene->rant[i]->turn = false;
                }

            }
                if (mainScene->rant[i]->getY()>mainScene->food[*ptr]->getY()){ //низ
                    if((mainScene->rant[i]->direction != GLUT_KEY_UP)&&(mainScene->rant[i]->turn))
                    {
                        mainScene->rant[i]->direction = GLUT_KEY_DOWN;
                        mainScene->rant[i]->turn = false;
                    }

                }
            if (mainScene->rant[i]->getX()<mainScene->food[*ptr]->getX()){// вправо
                if((mainScene->rant[i]->direction != GLUT_KEY_LEFT)&&(mainScene->rant[i]->turn))
                {
                    mainScene->rant[i]->direction = GLUT_KEY_RIGHT;
                    mainScene->rant[i]->turn = false;
                }

            }
                if (mainScene->rant[i]->getX()>mainScene->food[*ptr]->getX()){//ліво
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
        if((mainScene->rant[j]->getX() == mainScene->food[i]->getX())&&(mainScene->rant[j]->getY() == mainScene->food[i]->getY())){
            mainScene->rant[j]->invent=true;

            mainScene->food[i]->spawn();
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
        if (mainScene->rant[i]->getY()<mainScene->base[0].getY()){// верх
            if((mainScene->rant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->rant[i]->turn))
            {
                mainScene->rant[i]->direction = GLUT_KEY_UP;
                mainScene->rant[i]->turn = false;
            }
        }
            if (mainScene->rant[i]->getY()>mainScene->base[0].getY()){ //низ
                if((mainScene->rant[i]->direction != GLUT_KEY_UP)&&(mainScene->rant[i]->turn))
                {
                   mainScene->rant[i]->direction = GLUT_KEY_DOWN;
                   mainScene->rant[i]->turn = false;
                }
            }
        if (mainScene->rant[i]->getX()<mainScene->base[0].getX()){// вправо
            if((mainScene->rant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->rant[i]->turn))
            {
                mainScene->rant[i]->direction = GLUT_KEY_RIGHT;
                mainScene->rant[i]->turn = false;
            }
        }

            if (mainScene->rant[i]->getX()>mainScene->base[0].getX()){//ліво
                if((mainScene->rant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->rant[i]->turn))
                {
                    mainScene->rant[i]->direction = GLUT_KEY_LEFT;
                    mainScene->rant[i]->turn = false;


            }


    }
}
void Ant::eject(int i)
{

    if((mainScene->rant[i]->invent)&&((mainScene->rant[i]->getX() == mainScene->base[0].getX())&&(mainScene->rant[i]->getY() == mainScene->base[0].getY())))
    {
       mainScene->rant[i]->invent=false;
        mainScene->r_base.score++;

}
}
