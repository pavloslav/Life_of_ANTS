#ifndef R_ANT_H
#define R_ANT_H
#include "ant.h"

class R_ant: public Ant
{
public:

    R_ant();
    virtual void move(int i);
    //virtual void cut();
    virtual void drawSnake(int i);
};


#endif // R_ANT_H
