#include "colonyblock.h"
#include "colony.h"

ColonyBlock::ColonyBlock( std::shared_ptr<Scene> scene, int x, int y, const std::string& name, std::shared_ptr<Colony> col ) :
    Block( scene, x, y, name ), colony( col )
{
}

ColonyBlock::~ColonyBlock()
{
}

std::shared_ptr<Colony> ColonyBlock::getColony() const
{
    return colony;
}
