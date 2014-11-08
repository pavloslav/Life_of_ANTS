#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "ant.h"
#include "b_ant.h"
#include "r_ant.h"
#include "game.h"

using namespace std;

game settings;
R_ant *rant[20];
B_ant *bant[20];
B_base b_base;
R_base r_base;
food* m[20];
block base[WIDTH*HEIGHT], b_ant[WIDTH*HEIGHT], target[WIDTH*HEIGHT], r_ant[WIDTH*HEIGHT];


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





void DrawField()
  {
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
    for (int i=0; i<WIDTH; i+=settings.scale)
      {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
    for (int j=0; j<=HEIGHT; j+=settings.scale)
      {glVertex2f(0,j); glVertex2f(WIDTH,j);}
    glEnd();
}


void DrawBarr()
{
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
     for (int i=0; i<WIDTH; i+=settings.scale)
       {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
     for (int j=0; j<HEIGHT; j+=settings.scale)
       {glVertex2f(0,j); glVertex2f(WIDTH,j);}
     glEnd();

}




void food::draw_food()
    {

    glColor3f(0.0,1.0,1.0);
           glRectf(x*settings.scale,y*settings.scale,(x+1)*settings.scale,(y+1)*settings.scale);

}

void block::draw()
{
    glColor3f(0.0,1.0,0.0);
glVertex2f(x*settings.scale,y*settings.scale);
glVertex2f(x*settings.scale+settings.scale,y*settings.scale);
glVertex2f(x*settings.scale+settings.scale,y*settings.scale+settings.scale);
glVertex2f(x*settings.scale,y*settings.scale+settings.scale);
}


void R_base::draw()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(base[0].x + settings.scale, base[0].y);
    glVertex2f(base[0].x, base[0].y + settings.scale);
    glVertex2f(base[0].x - settings.scale, base[0].y);
    glVertex2f(base[0].x, base[0].y - settings.scale);
    glEnd();
}

void B_base::draw()
{
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(base[1].x + settings.scale, base[1].y);
    glVertex2f(base[1].x, base[1].y + settings.scale);
    glVertex2f(base[1].x - settings.scale, base[1].y);
    glVertex2f(base[1].x, base[1].y - settings.scale);
    glEnd();
}


void R_ant::DrawSnake(int i)
{
    glColor3f(1.0, 0.0, 0.0);
        glRectf(r_ant[i].x * 1, r_ant[i].y * 1, (r_ant[i].x + 0.9) * 1, (r_ant[i].y + 0.9) * 1);
}
void B_ant::DrawSnake(int i)
{
    glColor3f(0.0, 0.0, 0.0);
        glRectf(b_ant[i].x * 1, b_ant[i].y * 1, (b_ant[i].x + 0.9) * 1, (b_ant[i].y + 0.9) * 1);
}

void B_base::Print()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(280,180 );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + Score);
    }


void R_base::Print()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(15,180 );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + Score);
    system("cls");
        cout<<"R_base Score: "<< r_base.Score <<endl;
        cout<<"B_base Score: "<< b_base.Score <<endl;
        cout<<"Invent "<< rant[0]->Invent <<endl;

    }

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
