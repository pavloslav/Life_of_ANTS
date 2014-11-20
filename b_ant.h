#ifndef B_ANT_H
#define B_ANT_H

#include "ant.h"

class B_ant: public  Ant
{
public:
<<<<<<< HEAD
    B_ant( int x, int y, Base* base );
    virtual void drawSnake();
    virtual void move();
=======
    B_ant( int x, int y );
    virtual void drawSnake(int i);
    virtual void move(int i);
    virtual void go_home(int i);
    virtual void navig(double* targ, int *ptr , int i);
    virtual void search(int j);
    virtual void chek(int i);
    virtual void eat(int i);
    virtual void eject(int i);
>>>>>>> origin/master
};

#endif // B_ANT_H
