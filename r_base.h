#ifndef R_BASE_H
#define R_BASE_H

#include "base.h"
class Scene;

class R_base: public Base
{
public:
    int size;
    int StartPosX;
    int StartPosY;
    double Score;

    R_base( );
     void Print();
    void draw();
    void init();
};

#endif // R_BASE_H
