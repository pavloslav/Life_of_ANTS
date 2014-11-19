#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <cmath>

#include "block.h"

class Food : public virtual Block
{
public:
        Food();
        void draw_food();
        void spawn();
};

#endif // FOOD_H
