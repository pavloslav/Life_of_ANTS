#ifndef SCENE_H
#define SCENE_H

#include "ant.h"
#include "base.h"
#include "food.h"
#include "block.h"
#include "colony.h"
#include <vector>

class Food;
class Block;

class Scene
{
public:
    Scene();
    std::vector< Food * > food;
    std::vector< Colony * > colonies;
    Colony black, red;
    int delay;
    float scale;
    int winScale;
    int winPosX;
    int winPosY;

    void init();

    void drawField() const;
    void drawBar() const;
    void display() const;
    void allFoods();
    void keyboard(unsigned char key);
    void timer(int = 0);
    Base* nearestBase( ColonyBlock *who );
};

#endif // SCENE_H
