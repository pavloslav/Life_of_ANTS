#include "b_ant.h"
#include <GL/glut.h>
#include "scene.h"

B_ant::B_ant( int x, int y ) : Ant( x, y )
{
}

void B_ant::drawSnake(int i)
{
    glColor3f(0.0, 0.0, 0.0);
    glRectf(mainScene->bant[i]->getX() * 1, mainScene->bant[i]->getY() * 1, (mainScene->bant[i]->getX() + 0.9) * 1, (mainScene->bant[i]->getY() + 0.9) * 1);
}

void B_ant::navig(double* targ, int *ptr, int i)
{
       if(targ[*ptr]<=50)
    {

            if (mainScene->bant[i]->getY()<mainScene->food[*ptr]->getY()){// верх
                if((mainScene->bant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->bant[i]->turn))
                {
                    mainScene->bant[i]->direction = GLUT_KEY_UP;
                    mainScene->bant[i]->turn = false;
                }

            }
                if (mainScene->bant[i]->getY()>mainScene->food[*ptr]->getY()){ //низ
                    if((mainScene->bant[i]->direction != GLUT_KEY_UP)&&(mainScene->bant[i]->turn))
                    {
                        mainScene->bant[i]->direction = GLUT_KEY_DOWN;
                        mainScene->bant[i]->turn = false;
                    }

                }
            if (mainScene->bant[i]->getX()<mainScene->food[*ptr]->getX()){// вправо
                if((mainScene->bant[i]->direction != GLUT_KEY_LEFT)&&(mainScene->bant[i]->turn))
                {
                    mainScene->bant[i]->direction = GLUT_KEY_RIGHT;
                    mainScene->bant[i]->turn = false;
                }

            }
                if (mainScene->bant[i]->getX()>mainScene->food[*ptr]->getX()){//ліво
                    if((mainScene->bant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->bant[i]->turn))
                    {
                        mainScene->bant[i]->direction = GLUT_KEY_LEFT;
                        mainScene->bant[i]->turn = false;
                    }

                }
       }


            if(targ[*ptr]>=50)
            {
                        if((rand()% 3)<2){
                mainScene->bant[i]->direction = GLUT_KEY_END;
                mainScene->bant[i]->turn = false;
                        }
                        else
                            go_home(i);
            }

}

void B_ant::chek(int i)
{
    if (mainScene->bant[i]->invent==true){

        mainScene->bant[i]->go_home(i);
    }
    if (mainScene->bant[i]->invent==false)
        search(i);

}
void B_ant::go_home(int i)
{
        if (mainScene->bant[i]->getY()<mainScene->base[1].getY()){// верх
            if((mainScene->bant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->bant[i]->turn))
            {
                mainScene->bant[i]->direction = GLUT_KEY_UP;
                mainScene->bant[i]->turn = false;
            }
        }
            if (mainScene->bant[i]->getY()>mainScene->base[1].getY()){ //низ
                if((mainScene->bant[i]->direction != GLUT_KEY_UP)&&(mainScene->bant[i]->turn))
                {
                   mainScene->bant[i]->direction = GLUT_KEY_DOWN;
                   mainScene->bant[i]->turn = false;
                }
            }
        if (mainScene->bant[i]->getX()<mainScene->base[1].getX()){// вправо
            if((mainScene->bant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->bant[i]->turn))
            {
                mainScene->bant[i]->direction = GLUT_KEY_RIGHT;
                mainScene->bant[i]->turn = false;
            }
        }

            if (mainScene->bant[i]->getX()>mainScene->base[1].getX()){//ліво
                if((mainScene->bant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->bant[i]->turn))
                {
                    mainScene->bant[i]->direction = GLUT_KEY_LEFT;
                    mainScene->bant[i]->turn = false;


            }


    }
}


void B_ant::eject(int i)
{

    if((mainScene->bant[i]->invent)&&((mainScene->bant[i]->getX() == mainScene->base[1].getX())&&(mainScene->bant[i]->getY() == mainScene->base[1].getY())))
    {
       mainScene->bant[i]->invent=false;
        mainScene->b_base.score++;

}
}
void B_ant::move(int i){
        for(int j = 1; j > 0; j--){
                mainScene->bant[j]->setX( mainScene->bant[j-1]->getX() );
                mainScene->bant[j]->setY( mainScene->bant[j-1]->getY() );
        }
            switch (direction){
            case GLUT_KEY_UP :
                    mainScene->bant[i]->getY()++;
                    break;
            case GLUT_KEY_DOWN :
                    mainScene->bant[i]->getY()--;
                    break;
            case GLUT_KEY_LEFT :
                mainScene->bant[i]->getX()--;
                    break;
            case GLUT_KEY_RIGHT :
                   mainScene->bant[i]->getX()++;
                    break;
            case GLUT_KEY_END :
                    break;

        }

        if(mainScene->bant[i]->getX() < 0)mainScene->bant[i]->getX() += WIDTH;
        if(mainScene->bant[i]->getX() >= WIDTH)mainScene->bant[i]->getX() -= WIDTH;
        if(mainScene->bant[i]->getY() < 0)mainScene->bant[i]->getY() += HEIGHT;
        if(mainScene->bant[i]->getY() >= HEIGHT)mainScene->bant[i]->getY() -= HEIGHT;
}
void B_ant::search(int j)
{
        double size = 20;
        double targ[20];

        int n=0;
        for (int i=0;i<size;++i){     //перераховує масив food[i]
            targ[i] = mainScene->bant[j]->distance(*mainScene->food[i]);
            if(targ[i]<=targ[n]){
                n=i;
            }
        }
        navig(targ,&n,j );
}
