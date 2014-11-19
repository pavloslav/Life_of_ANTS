#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <cmath>
#include "scene.h"

class Food{
public:
        int x;
        int y;
        static Scene *mainScene;
        Food();
        void draw_food();
        void spawn();
};

#endif // FOOD_H
