#include "scene.h"
#include <GL/glut.h>
#include "colony.h"

Scene *Block::mainScene;

Scene::Scene() :
    black( 0.0, 0.0, 0.0,  15, 180 ),
    red  ( 1.0, 0.0, 0.0, 280, 180 ),
    delay ( 100 ),
    scale ( 1.0 ),
    winScale ( 5 ),
    winPosX ( 200 ),
    winPosY ( 100 )
{
    colonies.push_back( &black );
    colonies.push_back( &red );
    new Base( 15,  15, &red);
    new Base(270, 120, &black);
    for(int i=0;i<20;++i)
    {
        new Ant( rand()%30 + 250,
                 rand()%30 + 100,
                 &black );
        new Ant( rand()% 30,
                 rand()% 30,
                 &red );
        food.push_back( new Food() );
    }
    allFoods();
}

void Scene::drawField() const
{
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
    for (int i=0; i<WIDTH; i+=scale)
      {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
    for (int j=0; j<=HEIGHT; j+=scale)
      {glVertex2f(0,j); glVertex2f(WIDTH,j);}
    glEnd();
}

void Scene::drawBar() const
{
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
     for (int i=0; i<WIDTH; i+=scale)
       {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
     for (int j=0; j<HEIGHT; j+=scale)
       {glVertex2f(0,j); glVertex2f(WIDTH,j);}
     glEnd();
}

void keyboard(unsigned char key, int , int );
void timer(int = 0);
void display();

void Scene::display() const
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawField();
    for(unsigned int i=0;i<colonies.size();++i)
    {
        colonies[i]->draw();
    }
    for (unsigned int i=0;i<food.size();i++)
    {
        food[i]->draw();
    }
    glFlush();
    glutSwapBuffers();
    glutPostOverlayRedisplay();
}

void Scene::allFoods()
{
    for (int i=0;i<20;i++)
    {
        food[i]->spawn();
    }

}

void Scene::timer(int)
{
  display();
  for(int i=0;i<20;++i){
    red.ants[i]->action();
    black.ants[i]->action();
  }
  glutTimerFunc(50,::timer,0);
}

void Scene::keyboard(unsigned char key )
{
    switch (key) {

    case 'z':
        allFoods();

        break;
    default:
        break;
    }

}
