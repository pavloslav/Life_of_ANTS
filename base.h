#ifndef BASE_H
#define BASE_H

#include "colonyblock.h"

class Colony;

class Base : public ColonyBlock
{
public:
    Base( int x, int y, Colony *col );
    virtual ~Base();
    virtual void draw();
private:
};

#endif // BASE_H
