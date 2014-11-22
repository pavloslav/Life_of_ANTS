#ifndef ANT_H
#define ANT_H

#include "colonyblock.h"
#include "colony.h"
#include "base.h"
#include "food.h"

class Ant : public ColonyBlock
{
public:
    Ant( int x, int y, Colony* col );
    virtual ~Ant();
    virtual void draw();
    virtual void turnTo( Block *target );
    virtual void action();
    enum State {idle, goingToFood, carringFoodHome};

private:
    Block::Direction direction;
    State state;
    Block *target;
};
#endif // ANT_H
