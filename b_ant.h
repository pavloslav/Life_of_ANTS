#ifndef B_ANT_H
#define B_ANT_H

#include "ant.h"

class B_ant: public Ant
{
public:
    int direction;
    int size;
    bool turn;
    bool Invent;
    B_ant();
    void DrawSnake(int i);
    void move(int i);
     void go_home(int i);
    void navig(double* targ, int *ptr , int i);
        void search(int j);
        void chek(int i);
    void cut();
    void eject(int i);

};

#endif // B_ANT_H
