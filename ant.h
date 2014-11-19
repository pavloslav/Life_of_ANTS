#ifndef ANT_H
#define ANT_H

#include "block.h"
class Scene;

#define WIDTH 300
#define HEIGHT 150
#define BARR 50

class Ant : virtual public Block
{
private:
    double speed;
    double live;
    double speedAtack;

public:
    static Scene *mainScene;
    int size;
    bool turn;
    bool invent;
    int startPosX;
    int startPosY;
    int startSize;
    int direction;

    Ant( int x, int y );
    void setSpeed(double);
    double getSpeed() const;
    void setLive(double);
    double getLive() const;
    void setSpeedatack(double);
    double getSpeedatack() const;
    virtual void go_home(int i);
    //virtual void init()=0;
    virtual void drawSnake(int i)=0;
    virtual void search(int j);
    virtual void navig(double* targ, int *ptr , int i);
    virtual void move(int)=0;
    //virtual void go()=0;
    virtual void eject(int i);
    virtual void eat(int i);
    virtual void chek(int i);
};
#endif // ANT_H
