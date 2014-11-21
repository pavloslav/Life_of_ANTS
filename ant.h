#ifndef ANT_H
#define ANT_H

#include "colonyblock.h"

class Colony;
class Base;
class Food;

class Ant : public ColonyBlock
{
public:
    Ant( int x, int y, Colony* col );
    void setSpeed(double);
    double getSpeed() const;
    void setLive(double);
    double getLive() const;
    void setSpeedatack(double);
    double getSpeedatack() const;
    virtual void goHome();
    virtual void draw();
    virtual void search();
    virtual void navig(double value, Food *target );
    virtual void eject();
    virtual void eat();
    virtual void chek();
    virtual void goTo( Block *target );

    //virtual void deside();
    virtual void action();
private:
    double speed;
    double live;
    double speedAtack;
    int size;
    bool turn;
    bool isCarringFood;
    int startPosX;
    int startPosY;
    int startSize;

protected:
    Block::Direction direction;
};
#endif // ANT_H
