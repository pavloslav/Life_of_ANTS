#ifndef B_ANT_H
#define B_ANT_H

#include "ant.h"

class B_ant: public  Ant
{
public:
    B_ant( int x, int y, Base* base );
    virtual void drawSnake();
    virtual void move();
};

#endif // B_ANT_H
