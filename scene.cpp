#include "scene.h"
#include <GL/glut.h>

Scene::Scene()
{
     delay = 100;
     scale = 1;
     WinScale = 5;
     WinPosX = 200;
     WinPosY = 100;
}

void Scene::DrawField()
{
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
    for (int i=0; i<WIDTH; i+=scale)
      {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
    for (int j=0; j<=HEIGHT; j+=scale)
      {glVertex2f(0,j); glVertex2f(WIDTH,j);}
    glEnd();
}

void Scene::DrawBar()
{
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
     for (int i=0; i<WIDTH; i+=scale)
       {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
     for (int j=0; j<HEIGHT; j+=scale)
       {glVertex2f(0,j); glVertex2f(WIDTH,j);}
     glEnd();

}

void keyboard(unsigned char key, int x, int y);
void timer(int = 0);
void display();

void Scene::Display() {

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

void Scene::AllFoods()
{
    for (int i=0;i<20;i++){
        m[i]->spawn();
    }

}





void Scene::Timer(int)
{
  Display();
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

void Scene::Keyboard(unsigned char key, int , int )
{
    switch (key) {

    case 'z':
        AllFoods();

        break;
    default:
        break;
    }

}
