#ifndef R_ANT_H
#define R_ANT_H
#include "ant.h"

class R_ant: public Ant
{
public:
    int direction;
    int size;
    bool turn;
    bool Invent;
    R_ant();/*{
    turn = false;
    size = 1;
    int direction ;
    }*/
    void move(int i);
    void cut();
    void DrawSnake(int i);
    //void search(int j,food *m );
    //friend void search();
    //void eat();

};


#endif // R_ANT_H
