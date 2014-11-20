#ifndef ANT_H
#define ANT_H

#include "block.h"
class Base;
class Food;

class Ant : public Block
{
private:
    double speed;
    double live;
    double speedAtack;
    Base *home_;
    int size;
    bool turn;
    bool isCarringFood;
    int startPosX;
    int startPosY;
    int startSize;

protected:
    Block::Direction direction;

public:
    Ant( int x, int y, Base *home );
    void setSpeed(double);
    double getSpeed() const;
    void setLive(double);
    double getLive() const;
    void setSpeedatack(double);
    double getSpeedatack() const;
    virtual void goHome();
    virtual void draw()=0;
    virtual void search();
    virtual void navig(double value, Food *target );
    virtual void move()=0;
    virtual void eject();
    virtual void eat();
    virtual void chek();
    virtual void goTo( Block *target );

    //virtual void deside();
    virtual void action();
};
#endif // ANT_H
