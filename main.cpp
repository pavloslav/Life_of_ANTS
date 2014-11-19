#include <ctime>
#include <cstdlib>
#include <GL\glut.h>

#include "scene.h"
#include "ant.h"
#include "b_ant.h"
#include "r_ant.h"

#define VERSION "0.08"

using namespace std;

Scene mainScene;
Scene *Ant::mainScene = &::mainScene;
Scene *Base::mainScene = &::mainScene;
Scene *Block::mainScene = &::mainScene;

void keyboard(unsigned char key, int , int )
{
    mainScene.keyboard(key);
}

void timer(int = 0)
{
    mainScene.timer();
}

void display()
{
    mainScene.display();
}


int main(int argc, char **argv) {
    for(int i=0;i<20;++i)
    {
        mainScene.bant[i]= new B_ant( rand()%30+ 250,
                                      rand()%30+ 100);
        mainScene.rant[i]= new R_ant( rand()% 30,
                                      rand()% 30 );
        mainScene.food[i] = new Food();
    }

    srand(time(NULL));
    mainScene.allFoods();
    mainScene.base[0].setX(15);
    mainScene.base[0].setY(15);
    mainScene.base[1].setX(270);
    mainScene.base[1].setY(120);


glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(WIDTH*mainScene.winScale, BARR+HEIGHT*mainScene.winScale);
glutInitWindowPosition(mainScene.winPosX, mainScene.winPosY);
glutCreateWindow ("Ant " VERSION);
glClearColor(1.0,1.0,0.6,1.0);  //цвет фона
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,WIDTH,0,BARR+HEIGHT);
glutKeyboardFunc(keyboard);
glutDisplayFunc (display);

glutTimerFunc(50,timer,0);

glutMainLoop();
}
