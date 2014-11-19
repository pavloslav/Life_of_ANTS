#include "b_ant.h"
#include <GL/glut.h>
#include "scene.h"

B_ant::B_ant()
{
    invent = false;
    turn = false;
    size = startSize;
    direction = GLUT_KEY_RIGHT;
}
void B_ant::drawSnake(int i)
{
    glColor3f(0.0, 0.0, 0.0);
    glRectf(mainScene->b_ant[i].x * 1, mainScene->b_ant[i].y * 1, (mainScene->b_ant[i].x + 0.9) * 1, (mainScene->b_ant[i].y + 0.9) * 1);
}

void B_ant::navig(double* targ, int *ptr, int i)
{
       if(targ[*ptr]<=50)
    {

            if (mainScene->b_ant[i].y<mainScene->m[*ptr]->y){// верх
                if((mainScene->bant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->bant[i]->turn))
                {
                    mainScene->bant[i]->direction = GLUT_KEY_UP;
                    mainScene->bant[i]->turn = false;
                }

            }
                if (mainScene->b_ant[i].y>mainScene->m[*ptr]->y){ //низ
                    if((mainScene->bant[i]->direction != GLUT_KEY_UP)&&(mainScene->bant[i]->turn))
                    {
                        mainScene->bant[i]->direction = GLUT_KEY_DOWN;
                        mainScene->bant[i]->turn = false;
                    }

                }
            if (mainScene->b_ant[i].x<mainScene->m[*ptr]->x){// вправо
                if((mainScene->bant[i]->direction != GLUT_KEY_LEFT)&&(mainScene->bant[i]->turn))
                {
                    mainScene->bant[i]->direction = GLUT_KEY_RIGHT;
                    mainScene->bant[i]->turn = false;
                }

            }
                if (mainScene->b_ant[i].x>mainScene->m[*ptr]->x){//ліво
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
        if (mainScene->b_ant[i].y<mainScene->base[1].y){// верх
            if((mainScene->bant[i]->direction != GLUT_KEY_DOWN)&&(mainScene->bant[i]->turn))
            {
                mainScene->bant[i]->direction = GLUT_KEY_UP;
                mainScene->bant[i]->turn = false;
            }
        }
            if (mainScene->b_ant[i].y>mainScene->base[1].y){ //низ
                if((mainScene->bant[i]->direction != GLUT_KEY_UP)&&(mainScene->bant[i]->turn))
                {
                   mainScene->bant[i]->direction = GLUT_KEY_DOWN;
                   mainScene->bant[i]->turn = false;
                }
            }
        if (mainScene->b_ant[i].x<mainScene->base[1].x){// вправо
            if((mainScene->bant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->bant[i]->turn))
            {
                mainScene->bant[i]->direction = GLUT_KEY_RIGHT;
                mainScene->bant[i]->turn = false;
            }
        }

            if (mainScene->b_ant[i].x>mainScene->base[1].x){//ліво
                if((mainScene->bant[i]->direction != GLUT_KEY_RIGHT)&&(mainScene->bant[i]->turn))
                {
                    mainScene->bant[i]->direction = GLUT_KEY_LEFT;
                    mainScene->bant[i]->turn = false;


            }


    }
}


void B_ant::eject(int i)
{

    if((mainScene->bant[i]->invent)&&((mainScene->b_ant[i].x == mainScene->base[1].x)&&(mainScene->b_ant[i].y == mainScene->base[1].y)))
    {
       mainScene->bant[i]->invent=false;
        mainScene->b_base.score++;

}
}
void B_ant::move(int i){
        for(int j = 1; j > 0; j--){
                mainScene->b_ant[j].x = mainScene->b_ant[j-1].x;
                mainScene->b_ant[j].y = mainScene->b_ant[j-1].y;
        }
            switch (direction){
            case GLUT_KEY_UP :
                    mainScene->b_ant[i].y++;
                    break;
            case GLUT_KEY_DOWN :
                    mainScene->b_ant[i].y--;
                    break;
            case GLUT_KEY_LEFT :
                mainScene->b_ant[i].x--;
                    break;
            case GLUT_KEY_RIGHT :
                   mainScene->b_ant[i].x++;
                    break;
            case GLUT_KEY_END :
                    break;

        }

        if(mainScene->b_ant[i].x < 0)mainScene->b_ant[i].x += WIDTH;
        if(mainScene->b_ant[i].x >= WIDTH)mainScene->b_ant[i].x -= WIDTH;
        if(mainScene->b_ant[i].y < 0)mainScene->b_ant[i].y += HEIGHT;
        if(mainScene->b_ant[i].y >= HEIGHT)mainScene->b_ant[i].y -= HEIGHT;
}
void B_ant::search(int j)
{
        double size = 20;
        double targ[20];

        int n=0;
        for (int i=0;i<size;++i){     //перераховує масив m[i]
            double deltaX=mainScene->b_ant[j].x-mainScene->m[i]->x;
            double deltaY=mainScene->b_ant[j].y-mainScene->m[i]->y;
            double delta=((deltaX*deltaX)+(deltaY*deltaY));

            targ[i] = sqrt(delta);
            if(targ[i]<=targ[n]){
                n=i;
            }



        }
        navig(targ,&n,j );
}
