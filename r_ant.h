#ifndef R_ANT_H
#define R_ANT_H

#include "ant.h"

class R_ant: public Ant
{
public:
    R_ant( int x, int y, Base *base );
    virtual void move();
    //virtual void cut();
    virtual void drawSnake();
};


#endif // R_ANT_H
