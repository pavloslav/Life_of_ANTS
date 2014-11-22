#ifndef COLONY_H
#define COLONY_H

#include <vector>
#include "block.h"
#include "base.h"
#include <SDL2/SDL.h>

class Scene;
class Ant;

class Colony
{
public:
    Colony( Scene* scene, int r, int g, int b, int scoreX, int scoreY );
    Scene* mainScene;
    double score;
    int red, green, blue;//color of the colony
    int scorePosX, scorePosY;
    std::vector< Block * > bases;
    std::vector< Ant * > ants;
    virtual void draw();
    virtual void print();
    void SetSDLColor( SDL_Renderer* canvas );
};

#endif // COLONY_H
