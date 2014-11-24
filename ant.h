#ifndef ANT_H
#define ANT_H

#include "colonyblock.h"
#include "colony.h"
#include "base.h"
#include "food.h"

class Ant : public ColonyBlock
{
public:
    Ant(int x, int y, const std::string &name, Colony* col );
    virtual ~Ant();
    virtual void draw();
    virtual void turnTo( Block *target );
    virtual void action();
    enum State {idle, goingToFood, carringFoodHome};

private:
    Block::Direction direction;
    State state;
    Block *target;
    Label label;
};
#endif // ANT_H
