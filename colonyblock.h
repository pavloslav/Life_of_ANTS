#ifndef COLONYBLOCK_H
#define COLONYBLOCK_H

#include "block.h"
class Colony;

class ColonyBlock : public Block
{
public:
    ColonyBlock( int x,
                 int y,
                 const std::string &name,
                 std::shared_ptr<Colony> col );
    virtual ~ColonyBlock();
    std::shared_ptr<Colony> getColony() const;
    void draw() override = 0;

private:
    std::shared_ptr<Colony> colony;
};

#endif // COLONYBLOCK_H
