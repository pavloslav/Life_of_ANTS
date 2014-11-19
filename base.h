#ifndef BASE_H
#define BASE_H


#include "block.h"

class Scene;

class Base : public virtual Block
{
public:
    static Scene *mainScene;
    int size;
    int startPosX;
    int startPosY;
    double score;
    Base( );
    virtual void print() const =0;
    virtual void draw() const =0;
};

#endif // BASE_H
