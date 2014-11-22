#ifndef ANT_H
#define ANT_H

#include <SDL2/SDL.h>
#include "colonyblock.h"
#include "colony.h"
#include "base.h"
#include "food.h"

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
    virtual void draw();
    virtual void turnTo( Block *target );
    virtual void action();
    enum State {idle, goingToFood, carringFoodHome};

private:
    double speed;
    double live;
    double speedAtack;
    int size;
    int startPosX;
    int startPosY;
    int startSize;
    Block::Direction direction;
    State state;
    Block *target;
};
#endif // ANT_H
