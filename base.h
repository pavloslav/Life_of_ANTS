#ifndef BASE_H
#define BASE_H

#include "block.h"

class Scene;

class Base : public Block
{
public:
    int size;
    int startPosX;
    int startPosY;
    double score;
    Base( int x, int y );
    virtual void print() const =0;
    virtual void draw() const =0;
};

#endif // BASE_H
