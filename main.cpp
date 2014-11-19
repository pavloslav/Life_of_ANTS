#include <ctime>
#include <cstdlib>
#include <GL\freeglut.h>

#include "ant.h"
#include "b_ant.h"
#include "r_ant.h"
#include "game.h"

using namespace std;






void Ant::chek(int i)
{
    if (rant[i]->Invent==true){

        rant[i]->go_home(i);
    }
    if (rant[i]->Invent==false)
        search(i);

}

void B_ant::chek(int i)
{
    if (bant[i]->Invent==true){

        bant[i]->go_home(i);
    }
    if (bant[i]->Invent==false)
        search(i);

}



void Ant::go_home(int i)
{
        if (r_ant[i].y<base[0].y){// верх
            if((rant[i]->direction != GLUT_KEY_DOWN)&&(rant[i]->turn))
            {
                rant[i]->direction = GLUT_KEY_UP;
                rant[i]->turn = false;
            }
        }
            if (r_ant[i].y>base[0].y){ //низ
                if((rant[i]->direction != GLUT_KEY_UP)&&(rant[i]->turn))
                {
                   rant[i]->direction = GLUT_KEY_DOWN;
                   rant[i]->turn = false;
                }
            }
        if (r_ant[i].x<base[0].x){// вправо
            if((rant[i]->direction != GLUT_KEY_RIGHT)&&(rant[i]->turn))
            {
                rant[i]->direction = GLUT_KEY_RIGHT;
                rant[i]->turn = false;
            }
        }

            if (r_ant[i].x>base[0].x){//ліво
                if((rant[i]->direction != GLUT_KEY_RIGHT)&&(rant[i]->turn))
                {
                    rant[i]->direction = GLUT_KEY_LEFT;
                    rant[i]->turn = false;


            }


    }
}

void B_ant::go_home(int i)
{
        if (b_ant[i].y<base[1].y){// верх
            if((bant[i]->direction != GLUT_KEY_DOWN)&&(bant[i]->turn))
            {
                bant[i]->direction = GLUT_KEY_UP;
                bant[i]->turn = false;
            }
        }
            if (b_ant[i].y>base[1].y){ //низ
                if((bant[i]->direction != GLUT_KEY_UP)&&(bant[i]->turn))
                {
                   bant[i]->direction = GLUT_KEY_DOWN;
                   bant[i]->turn = false;
                }
            }
        if (b_ant[i].x<base[1].x){// вправо
            if((bant[i]->direction != GLUT_KEY_RIGHT)&&(bant[i]->turn))
            {
                bant[i]->direction = GLUT_KEY_RIGHT;
                bant[i]->turn = false;
            }
        }

            if (b_ant[i].x>base[1].x){//ліво
                if((bant[i]->direction != GLUT_KEY_RIGHT)&&(bant[i]->turn))
                {
                    bant[i]->direction = GLUT_KEY_LEFT;
                    bant[i]->turn = false;


            }


    }
}

void Ant::eject(int i)
{

    if((rant[i]->Invent)&&((r_ant[i].x == base[0].x)&&(r_ant[i].y == base[0].y)))
    {
       rant[i]->Invent=false;
        r_base.Score++;

}
}
void B_ant::eject(int i)
{

    if((bant[i]->Invent)&&((b_ant[i].x == base[1].x)&&(b_ant[i].y == base[1].y)))
    {
       bant[i]->Invent=false;
        b_base.Score++;

}
}

void Ant::eat(int j){
    for(int i=0;i<20;++i)
    {
        if((r_ant[j].x == m[i]->x)&&(r_ant[j].y == m[i]->y)){
            rant[j]->Invent=true;

        m[i]->spawn();
        }
}
}
void B_ant::eat(int j){
    for(int i=0;i<20;++i)
    {
        if((b_ant[j].x == m[i]->x)&&(b_ant[j].y == m[i]->y)){
            bant[j]->Invent=true;

        m[i]->spawn();
        }
}
}
void allFoods()
{
    for (int i=0;i<20;i++){
        m[i]->spawn();
    }

}

void food::spawn(){
        x = (rand()%WIDTH);
        y = (rand()%HEIGHT);
        for(int i = 0; i < 10; i++){
                if((x == r_ant[0].x)&&(y == r_ant[0].y))spawn();
        }
}

void R_ant::move(int i){
        for(int j = 1; j > 0; j--){
                r_ant[j].x = r_ant[j-1].x;
                r_ant[j].y = r_ant[j-1].y;
        }
            switch (direction){
            case GLUT_KEY_UP :
                    r_ant[i].y++;
                    break;
            case GLUT_KEY_DOWN :
                    r_ant[i].y--;
                    break;
            case GLUT_KEY_LEFT :
                r_ant[i].x--;
                    break;
            case GLUT_KEY_RIGHT :
                   r_ant[i].x++;
                    break;
            case GLUT_KEY_END :
                    break;

        }

        if(r_ant[i].x < 0)r_ant[i].x += WIDTH;
        if(r_ant[i].x >= WIDTH)r_ant[i].x -= WIDTH;
        if(r_ant[i].y < 0)r_ant[i].y += HEIGHT;
        if(r_ant[i].y >= HEIGHT)r_ant[i].y -= HEIGHT;
}

void B_ant::move(int i){
        for(int j = 1; j > 0; j--){
                b_ant[j].x = b_ant[j-1].x;
                b_ant[j].y = b_ant[j-1].y;
        }
            switch (direction){
            case GLUT_KEY_UP :
                    b_ant[i].y++;
                    break;
            case GLUT_KEY_DOWN :
                    b_ant[i].y--;
                    break;
            case GLUT_KEY_LEFT :
                b_ant[i].x--;
                    break;
            case GLUT_KEY_RIGHT :
                   b_ant[i].x++;
                    break;
            case GLUT_KEY_END :
                    break;

        }

        if(b_ant[i].x < 0)b_ant[i].x += WIDTH;
        if(b_ant[i].x >= WIDTH)b_ant[i].x -= WIDTH;
        if(b_ant[i].y < 0)b_ant[i].y += HEIGHT;
        if(b_ant[i].y >= HEIGHT)b_ant[i].y -= HEIGHT;
}


void display() {

     glClear(GL_COLOR_BUFFER_BIT);

    DrawField();
    for(int i=0;i<20;++i)
    {
    rant[i]->DrawSnake(i);
    bant[i]->DrawSnake(i);
    }
    r_base.draw();
    b_base.draw();
    r_base.Print();
    b_base.Print();


   for (int i=0;i<20;i++)
     m[i]->draw_food();

   glFlush();
   glutSwapBuffers();
   glutPostOverlayRedisplay();
}



void timer(int = 0)
{
  display();
  for(int i=0;i<20;++i){
  rant[i]->turn = true;
  rant[i]->chek(i);
  rant[i]->move(i);
  rant[i]->eat(i);
  rant[i]->eject(i);

  bant[i]->turn = true;
  bant[i]->chek(i);
  bant[i]->move(i);
  bant[i]->eat(i);
  bant[i]->eject(i);
  }


 glutTimerFunc(50,timer,0);
}



void keyboard(unsigned char key, int x, int y)
{
    switch (key) {

    case 'z':
        allFoods();

        break;
    default:
        break;
    }

}


int main(int argc, char **argv) {
    for(int i=0;i<20;++i)
    {
        rant[i]= new R_ant;
        bant[i]= new B_ant;
        m[i] = new food;
        b_ant[i].x=(rand()%30+ 250);
        b_ant[i].y=(rand()%30+ 100);
        r_ant[i].x=(rand()% 30);
        r_ant[i].y=(rand()% 30);
    }

    srand(time(NULL));
    allFoods();
    base[0].x=15;
    base[0].y=15;
    base[1].x = 270;
    base[1].y = 120;


glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(WIDTH*settings.WinScale, BARR+HEIGHT*settings.WinScale);
glutInitWindowPosition(settings.WinPosX, settings.WinPosY);
glutCreateWindow ("Ant 0.05");
glClearColor(1.0,1.0,0.6,1.0);  //цвет фона
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,WIDTH,0,BARR+HEIGHT);
glutKeyboardFunc(keyboard);
glutDisplayFunc (display);

glutTimerFunc(50,timer,0);

glutMainLoop();
}
