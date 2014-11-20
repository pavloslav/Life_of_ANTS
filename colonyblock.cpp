#include "colonyblock.h"
#include "colony.h"

ColonyBlock::ColonyBlock( int x, int y, Colony *col ) :
    Block( x, y ), colony( col )
{
}

Colony *ColonyBlock::getColony() const
{
    return colony;
}
