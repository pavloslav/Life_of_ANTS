#ifndef COLONY_H
#define COLONY_H

#include <vector>

#include "block.h"
#include "graphics.h"
#include "label.h"

class Base;
class Scene;
class Ant;

class Colony
{
public:
    Colony(Scene* scene, Color col, int scoreX, int scoreY );
    virtual ~Colony();

    Scene* mainScene;
    double score;
    Color color;
    int scorePosX, scorePosY;
    std::vector< Block * > bases;
    std::vector< Ant * > ants;
    Label label;
    virtual void draw();
    virtual void forgetBase( Block *what );
    virtual void forgetAnt( Block *what );
};

#endif // COLONY_H
