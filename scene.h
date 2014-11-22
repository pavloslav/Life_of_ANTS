#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "food.h"
#include "block.h"
#include "colony.h"
#include "graphics.h"

class Scene
{
public:
    Scene( Graphics *gr );
    std::vector< Block * > food;
    std::vector< Colony * > colonies;
    Colony black, red;
    int delay;
    float scale;
    int winScale;
    int winPosX;
    int winPosY;
    bool quit;
    Graphics *graphics;

    void init();

    void drawField();
    virtual void draw();
    void allFoods();
    virtual void processEvents();
    virtual void action();
    virtual ~Scene();
};

#endif // SCENE_H
