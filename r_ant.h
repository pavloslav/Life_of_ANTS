#ifndef R_ANT_H
#define R_ANT_H
#include "ant.h"

class R_ant: public virtual Ant
{
public:

    R_ant( int x, int y );
    virtual void move(int i);
    //virtual void cut();
    virtual void drawSnake(int i);
};


#endif // R_ANT_H
