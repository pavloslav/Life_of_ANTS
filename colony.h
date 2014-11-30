#ifndef COLONY_H
#define COLONY_H

#include <vector>
#include <memory>

#include "block.h"
#include "graphics.h"
#include "label.h"

class Base;
class Scene;
class Ant;

class Colony : public std::enable_shared_from_this<Colony>
{
public:
    Colony( std::shared_ptr<Scene> scene, Color col, const ScreenPoint& scoreLocation );
    virtual ~Colony();

    std::shared_ptr<Scene> mainScene;
    double score;
    Color color;
    Label label;
    virtual void draw();
    virtual void action();
    std::shared_ptr<Block> createBase( const ModelPoint& location, const std::string &name );
    std::shared_ptr<Block> createAnt(const ModelPoint &location, const std::string &name );
    void forgetBase( std::weak_ptr<Block> what );
    void forgetAnt( std::weak_ptr<Block> what );

    std::vector< std::shared_ptr< Block > > bases;
private:
    std::vector< std::shared_ptr< Ant > > ants;

};

#endif // COLONY_H
