#ifndef FOOD_H
#define FOOD_H

#include "block.h"
#include "label.h"

class Food : public Block
{
public:
    Food(const ModelPoint &location, const std::string& name );
    virtual ~Food();
    void draw() override;
private:
    Label label;
};

#endif // FOOD_H
