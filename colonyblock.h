#ifndef COLONYBLOCK_H
#define COLONYBLOCK_H

#include "block.h"
class Colony;

class ColonyBlock : public Block
{
public:
    ColonyBlock( int x, int y, Colony *col);
    Colony *getColony() const;
    virtual void draw() = 0;
private:
    Colony *colony;
};

#endif // COLONYBLOCK_H
