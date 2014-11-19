#include "scene.h"

Scene::Scene()
{
}

void Scene::DrawField()
{
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
    for (int i=0; i<WIDTH; i+=settings.scale)
      {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
    for (int j=0; j<=HEIGHT; j+=settings.scale)
      {glVertex2f(0,j); glVertex2f(WIDTH,j);}
    glEnd();
}


void Scene::DrawBarr()
{
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
     for (int i=0; i<WIDTH; i+=settings.scale)
       {glVertex2f(i,0); glVertex2f(i,HEIGHT);}
     for (int j=0; j<HEIGHT; j+=settings.scale)
       {glVertex2f(0,j); glVertex2f(WIDTH,j);}
     glEnd();

}
