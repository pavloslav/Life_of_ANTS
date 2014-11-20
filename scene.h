#ifndef SCENE_H
#define SCENE_H

#include "b_ant.h"
#include "r_ant.h"
#include "r_base.h"
#include "b_base.h"
#include "food.h"
#include "block.h"

class Food;
class Block;

class Scene
{
public:
    Scene();
    R_ant *rant[20];
    B_ant *bant[20];
    B_base *b_base;
    R_base *r_base;
    Food* food[20];
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
};

void search(Block* ant, int j,Food* m);
#endif // SCENE_H
