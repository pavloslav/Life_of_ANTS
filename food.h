#ifndef FOOD_H
#define FOOD_H

#include "block.h"

class Food : public Block
{
public:
        Food();
        virtual void draw();
        void spawn();
};

#endif // FOOD_H