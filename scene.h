#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "food.h"
#include "block.h"
#include "colony.h"
#include "graphics.h"
#include "label.h"
#include <memory>

class Scene : public std::enable_shared_from_this<Scene>
{
public:
    Scene( std::shared_ptr<Graphics> gr, int w, int h );
    virtual ~Scene();

    std::vector< std::shared_ptr<Block> > food;
    int fieldWidth, fieldHeight;
    bool quit;
    std::shared_ptr<Graphics> graphics;
    Color foodColor;
    double FPS;

    void init();
    std::shared_ptr<Colony> createColony( Color col, int scoreX, int scoreY );
    std::shared_ptr<Block> createFood( const std::string& name );

    virtual void draw();
    void allFoods();
    virtual void processEvents();
    virtual void action();

    void forgetFood( std::weak_ptr<Block> what );
    void forgetColony( std::weak_ptr<Colony> what );
private:
    Label labelFPS;
    std::vector< std::shared_ptr<Colony> > colonies;

};

#endif // SCENE_H
