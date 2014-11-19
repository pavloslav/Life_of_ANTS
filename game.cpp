#include "game.h"

game::game()
{
    delay = 100;
    scale = 1;
    WinScale = 5;
    WinPosX = 200;
    WinPosY = 100;
}




R_base::R_base()
{
    size = 1;
    Score = 0;
    StartPosX = 1;
    StartPosY = 1;
}

void R_base::draw()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f( scene->base[0].x + settings.scale, base[0].y);
    glVertex2f( scene->base[0].x, base[0].y + settings.scale);
    glVertex2f( scene->base[0].x - settings.scale, base[0].y);
    glVertex2f( scene->base[0].x, base[0].y - settings.scale);
    glEnd();
}
void R_base::Print()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(15,180 );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + Score);
    system("cls");
        cout<<"R_base Score: "<< scene->r_base.Score <<endl;
        cout<<"B_base Score: "<< scene->b_base.Score <<endl;
        cout<<"Invent "<< rant[0]->Invent <<endl;

    }
B_base::B_base()
{
    size = 1;
    Score = 0;
    StartPosX = 1;
    StartPosY = 1;
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

void B_base::Print()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(280,180 );
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0' + Score);
}
block::block()
{

    x = 1;
    y = 1;
}

void block::draw()
{
    glColor3f(0.0,1.0,0.0);
glVertex2f(x*settings.scale,y*settings.scale);
glVertex2f(x*settings.scale+settings.scale,y*settings.scale);
glVertex2f(x*settings.scale+settings.scale,y*settings.scale+settings.scale);
glVertex2f(x*settings.scale,y*settings.scale+settings.scale);
}

food::food()
{
x = 1;
y = 1;
}


void food::draw_food()
{
    glColor3f(0.0,1.0,1.0);
    glRectf(x*settings.scale,y*settings.scale,(x+1)*settings.scale,(y+1)*settings.scale);
}

