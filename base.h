#ifndef BASE_H
#define BASE_H

#include "colonyblock.h"

class Colony;

class Base : public ColonyBlock
{
public:
    Base( std::shared_ptr<Scene> scene, int x, int y, const std::string &name,  std::shared_ptr<Colony> col );
    virtual ~Base();
    virtual void draw();

private:

};

#endif // BASE_H
