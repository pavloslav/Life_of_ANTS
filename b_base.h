#ifndef B_BASE_H
#define B_BASE_H

#include "base.h"

class B_base: public Base
{
public:
    int size;
    int StartPosX;
    int StartPosY;
    double Score;

    B_base( );
     void Print();
    void draw();
    void init();
};

#endif // B_BASE_H
