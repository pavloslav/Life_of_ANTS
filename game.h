#include <iostream>
#include <math.h>
#include "ant.h"
#ifndef GAME_H
#define GAME_H





class game{
public:
        int delay;
        float scale;
        int WinScale;
        int WinPosX;
        int WinPosY;
        game();

        void init();
};



class Base
{
public:
    int size;
    int StartPosX;
    int StartPosY;
    double Score;

    Base();
     void Print();
    void draw();
    void init();
};


class B_base: public Base
{
public:
    int size;
    int StartPosX;
    int StartPosY;
    double Score;

    B_base();

    //std::ostream& operator« (ostreamSc s, const complex & z)
   friend std::ostream& operator<<(std::ostream &os,Base& b)
    {
        //system("cls");
            return os <<"Score "<< b.Score ;
             //os;
    }

     void Print();
    void draw();
    void init();
};

class R_base: public Base
{
public:
    int size;
    int StartPosX;
    int StartPosY;
    double Score;

    R_base();

    //std::ostream& operator« (ostreamSc s, const complex & z)
   friend std::ostream& operator<<(std::ostream &os,R_base& r)
    {
        //system("cls");
            return os <<"Score "<< r.Score ;
             //os;
    }

     void Print();
    void draw();
    void init();
};






class block {
public:
        int x;
        int y;
        block();

void draw();
};


class food{
public:
        int x;
        int y;
        food();
        void draw_food();
        void spawn();
};
void search(block* ant, int j,food* m);


#endif // GAME_H
