#include "b_ant.h"

B_ant::B_ant()
{
    Invent = false;
    turn = false;
    size = Ant::StartSize;
    direction = GLUT_KEY_RIGHT;
    //set_speed(25);
}
void B_ant::DrawSnake(int i)
{
    glColor3f(0.0, 0.0, 0.0);
        glRectf(b_ant[i].x * 1, b_ant[i].y * 1, (b_ant[i].x + 0.9) * 1, (b_ant[i].y + 0.9) * 1);
}

void B_ant::navig(double* targ, int *ptr, int i)
{
    int x;
       if(targ[*ptr]<=50)
    {

            if (b_ant[i].y<m[*ptr]->y){// верх
                if((bant[i]->direction != GLUT_KEY_DOWN)&&(bant[i]->turn))
                {
                    bant[i]->direction = GLUT_KEY_UP;
                    bant[i]->turn = false;
                }

            }
                if (b_ant[i].y>m[*ptr]->y){ //низ
                    if((bant[i]->direction != GLUT_KEY_UP)&&(bant[i]->turn))
                    {
                        bant[i]->direction = GLUT_KEY_DOWN;
                        bant[i]->turn = false;
                    }

                }
            if (b_ant[i].x<m[*ptr]->x){// вправо
                if((bant[i]->direction != GLUT_KEY_LEFT)&&(bant[i]->turn))
                {
                    bant[i]->direction = GLUT_KEY_RIGHT;
                    bant[i]->turn = false;
                }

            }
                if (b_ant[i].x>m[*ptr]->x){//ліво
                    if((bant[i]->direction != GLUT_KEY_RIGHT)&&(bant[i]->turn))
                    {
                        bant[i]->direction = GLUT_KEY_LEFT;
                        bant[i]->turn = false;
                    }

                }
       }


            if(targ[*ptr]>=50)
            {

                x = (rand()% 3);
                        if(x<2){
                bant[i]->direction = GLUT_KEY_END;
                bant[i]->turn = false;
                        }
                        else
                            go_home(i);
            }

}
