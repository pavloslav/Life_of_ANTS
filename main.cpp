#include <ctime>
#include <cstdlib>
#include <GL\glut.h>

#include "scene.h"
#include "block.h"

#define VERSION "0.09"

using namespace std;

void keyboard(unsigned char key, int , int )
{
    Block::mainScene->keyboard(key);
}

void timer(int = 0)
{
    Block::mainScene->timer();
}

void display()
{
    Block::mainScene->display();
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    Block::mainScene = new Scene();

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(WIDTH*Block::mainScene->winScale, BARR+HEIGHT*Block::mainScene->winScale);
    glutInitWindowPosition(Block::mainScene->winPosX, Block::mainScene->winPosY);
    glutCreateWindow ("Ant " VERSION);
    glClearColor(1.0,1.0,0.6,1.0);  //цвет фона
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, BARR+HEIGHT);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc (display);

    glutTimerFunc(50,timer,0);

    glutMainLoop();
}
