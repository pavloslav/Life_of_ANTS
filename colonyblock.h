#ifndef COLONYBLOCK_H
#define COLONYBLOCK_H

#include "block.h"
class Colony;

class ColonyBlock : public Block
{
    Colony *colony;
public:
    ColonyBlock( int x, int y, Colony *col);
    Colony *getColony() const;
};

#endif // COLONYBLOCK_H
