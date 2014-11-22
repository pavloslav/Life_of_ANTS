#ifndef FOOD_H
#define FOOD_H

#include "block.h"

class Food : public Block
{
public:
    Food();
    virtual ~Food();
    virtual void draw();
};

#endif // FOOD_H
