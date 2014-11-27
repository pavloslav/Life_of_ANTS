#include "colonyblock.h"
#include "colony.h"

ColonyBlock::ColonyBlock(int x, int y, const std::string& name, std::shared_ptr<Colony> col ) :
    Block( x, y, name ), colony( col )
{
}

ColonyBlock::~ColonyBlock()
{
}

std::shared_ptr<Colony> ColonyBlock::getColony() const
{
    return colony;
}
