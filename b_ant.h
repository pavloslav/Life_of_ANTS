#ifndef B_ANT_H
#define B_ANT_H

#include "ant.h"

class B_ant: public virtual Ant
{
public:
    B_ant( int x, int y );
    virtual void drawSnake(int i);
    virtual void move(int i);
    virtual void go_home(int i);
    virtual void navig(double* targ, int *ptr , int i);
    virtual void search(int j);
    virtual void chek(int i);
    //virtual void cut();
    virtual void eject(int i);
};

#endif // B_ANT_H
