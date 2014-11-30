#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "food.h"
#include "block.h"
#include "colony.h"
#include "label.h"

class Scene : public std::enable_shared_from_this<Scene>
{
public:
    Scene(const ModelPoint &size);
    virtual ~Scene();

    ModelRectangle map;
    Color foodColor;
    double FPS;
    std::vector< std::shared_ptr<Block> > food;

    void init();
    std::shared_ptr<Colony> createColony( Color col, ScreenPoint scoreLocation );
    std::shared_ptr<Block> createFood( const ModelPoint& location, const std::string& name );

    virtual void draw();
    void resetFood();
    virtual void action();

    void forgetFood( std::weak_ptr<Block> what );
    void forgetColony( std::weak_ptr<Colony> what );

private:
    Label labelFPS;
    std::vector< std::shared_ptr<Colony> > colonies;

};

#endif // SCENE_H
