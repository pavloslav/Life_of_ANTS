#ifndef BASE_H
#define BASE_H

#include "colonyblock.h"

class Colony;

class Base : public ColonyBlock
{
public:
    Base( int x, int y, Colony *col );
    virtual void print() const;
    virtual void draw() const;
private:
    int size;
    int startPosX;
    int startPosY;
};

#endif // BASE_H
