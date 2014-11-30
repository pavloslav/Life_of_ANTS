#include "scene.h"

#include <SDL2/SDL.h>
#include <algorithm>
#include <sstream>
#include <cstring>

#include "ant.h"
#include "graphics.h"
#include "app.h"

Scene::Scene( const ModelPoint& size ) :
    map( ModelPoint( 0.0, 0.0 ), size ),
    foodColor( ColorBlue ),
    FPS( 0.0 ),
    labelFPS( App::getApp()->getGraphics()->font, ScreenPoint( 200, 10 ), ColorGreen )
{
}

Scene::~Scene()
{
}

void Scene::init()
{
    auto red   = createColony( ColorRed  , ScreenPoint( 440, 10 ) );
    auto black = createColony( ColorBlack, ScreenPoint( 15, 10 ) );
    red  ->createBase( ModelPoint( 15, 15 )                             , "Red_0"   );
    black->createBase( ModelPoint( FIELD_WIDTH - 15, FIELD_HEIGHT - 15 ), "Black_0" );
    std::stringstream name;
    for(int i=0;i<OBJECTS;++i)
    {
        name.str( "" );
        name << "Ant_" << i;
        black->createAnt( ModelPoint( black->bases[0]->getPlace()
                                     + ModelPoint( rand() % 31 - 15, rand() % 31 - 15 ) ),
                          name.str() );
        red  ->createAnt( ModelPoint( red  ->bases[0]->getPlace()
                                     + ModelPoint( rand() % 31 - 15, rand() % 31 - 15 ) ),
                          name.str() );
        name.str( "" );
        name << "Food_" << i;
        createFood( ModelPoint( rand() % int(map.size.getX()), rand() % int(map.size.getY()) ),
                    name.str() );
    }
}

std::shared_ptr<Colony> Scene::createColony(Color col, ScreenPoint scoreLocation)
{
    auto colony = std::make_shared<Colony>( shared_from_this(), col, scoreLocation );
    colonies.push_back( colony );
    return colony;
}

std::shared_ptr<Block> Scene::createFood( const ModelPoint& location, const std::string &name)
{
    auto newFood = std::make_shared<Food>( location, name );
    food.push_back( newFood );
    return newFood;
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
            createFood( ModelPoint( rand() % int(map.size.getX()), rand() % int(map.size.getY()) ),
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
