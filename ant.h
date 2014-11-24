#ifndef ANT_H
#define ANT_H

#include "colonyblock.h"
#include "colony.h"
#include "base.h"
#include "food.h"

class Ant : public ColonyBlock
{
public:
    Ant( std::shared_ptr<Scene> scene,
         int x,
         int y,
         const std::string &name,
         std::shared_ptr<Colony> col );
    virtual ~Ant();
    void draw() override;
    virtual void turnTo(std::weak_ptr<Block> who );
    virtual void action();
    enum State { idle, goingToFood, carringFoodHome };

private:
    Block::Direction direction;
    State state;
    std::weak_ptr<Block> target_;
    std::unique_ptr<Label> label;
};
#endif // ANT_H
