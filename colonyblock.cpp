#include "colonyblock.h"
#include "colony.h"

ColonyBlock::ColonyBlock(const ModelPoint &location, const std::string& name, std::shared_ptr<Colony> col ) :
    Block( location, name ), colony( col )
{
}

ColonyBlock::~ColonyBlock()
{
}

std::shared_ptr<Colony> ColonyBlock::getColony() const
{
    return colony;
}
