#include "scene.h"

#include <SDL2/SDL.h>
#include <algorithm>
#include <sstream>
#include <cstring>

#include "ant.h"
#include "graphics.h"
#include "app.h"

Scene::Scene( int w, int h ) :
    fieldWidth( w ),
    fieldHeight( h ),
    foodColor( ColorBlue ),
    FPS( 0.0 ),
    labelFPS( App::getApp()->getGraphics()->font, 200, 10, ColorGreen )
{
}

Scene::~Scene()
{
}

void Scene::init()
{
    auto red   = createColony( ColorRed  , 440, 10 );
    auto black = createColony( ColorBlack,  15, 10 );
    red  ->createBase( 15,               15,                "Red_0"   );
    black->createBase( FIELD_WIDTH - 15, FIELD_HEIGHT - 15, "Black_0" );
    std::stringstream name;
    for(int i=0;i<OBJECTS;++i)
    {
        name.str( "" );
        name << "Ant_" << i;
        black->createAnt( rand() % 31 - 15 + black->bases[0]->getX(),
                          rand() % 31 - 15 + black->bases[0]->getY(),
                          name.str() );
        red  ->createAnt( rand() % 31 - 15 + red->bases[0]->getX(),
                          rand() % 31 - 15 + red->bases[0]->getY(),
                          name.str() );
        name.str( "" );
        name << "Food_" << i;
        createFood( rand() % fieldWidth,
                    rand() % fieldHeight,
                    name.str() );
    }
}

std::shared_ptr<Colony> Scene::createColony(Color col, int scoreX, int scoreY)
{
    colonies.push_back( std::make_shared<Colony>( shared_from_this(), col, scoreX, scoreY ));
    return colonies.back();
}

std::shared_ptr<Block> Scene::createFood(int x, int y, const std::string &name)
{
    food.push_back( std::make_shared<Food>( x, y, name ) );
    return food.back();
}

void Scene::forgetFood( std::weak_ptr<Block> what )
{
    std::shared_ptr<Block> existingWhat( what.lock() );
    if( existingWhat )
    {
        std::string name = existingWhat->getName();
        food.erase( std::remove( food.begin(), food.end(), existingWhat ), food.end() );
        if( !App::getApp()->isQuiting )
        {
            createFood( rand() % fieldWidth,
                        rand() % fieldHeight,
                        name );
        }
    }
}

void Scene::forgetColony(std::weak_ptr<Colony> what)
{
    std::shared_ptr<Colony> existingWhat( what.lock() );
    if( existingWhat )
    {
        colonies.erase( std::remove( colonies.begin(), colonies.end(), existingWhat ), colonies.end() );
    }
}

void Scene::action()
{
    for( auto &colony : colonies )
    {
        colony->action();
    }
    labelFPS.setText("FPS: ") << FPS;
}

void Scene::draw()
{
    const std::shared_ptr<Graphics>& graphics = App::getApp()->getGraphics();
    graphics->setColor( ColorYellow );
    int result = SDL_RenderClear( graphics->renderer );
    SDL_assert( result >= 0 );
    for( auto &colony : colonies )
    {
        colony->draw();
    }
    for ( auto &meal : food )
    {
        meal->draw();
    }
    labelFPS.draw();

}

void Scene::resetFood()
{
    for ( auto &meal : food )
    {
        forgetFood( meal );
    }

}
