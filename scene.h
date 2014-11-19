class Scene;

#ifndef SCENE_H
#define SCENE_H

#include "ant.h"
#include "b_ant.h"
#include "r_ant.h"
#include "game.h"

class Scene
{
public:
    Scene();
    R_ant *rant[20];
    B_ant *bant[20];
    B_base b_base;
    R_base r_base;
    food* m[20];
    block base[WIDTH*HEIGHT], b_ant[WIDTH*HEIGHT], target[WIDTH*HEIGHT], r_ant[WIDTH*HEIGHT];
    game settings;

    void DrawField();
    void DrawBar();
};

#endif // SCENE_H
