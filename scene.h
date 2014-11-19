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
    B_base b_base;
    R_base r_base;
    Food* m[20];
    Block base[WIDTH*HEIGHT], b_ant[WIDTH*HEIGHT], target[WIDTH*HEIGHT], r_ant[WIDTH*HEIGHT];
    int delay;
    float scale;
    int WinScale;
    int WinPosX;
    int WinPosY;

    void init();

    void DrawField();
    void DrawBar();
    void Display();
    void AllFoods();
    void Keyboard(unsigned char key, int x, int y);
    void Timer(int = 0);
};

void search(Block* ant, int j,Food* m);
#endif // SCENE_H
