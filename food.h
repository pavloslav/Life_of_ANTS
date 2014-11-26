#ifndef FOOD_H
#define FOOD_H

#include "block.h"
#include "label.h"

class Food : public Block
{
public:
    Food( std::shared_ptr<Scene> scene, const std::string& name );
    virtual ~Food();
    virtual void draw();
private:
    Label label;
};

#endif // FOOD_H
