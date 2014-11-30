#include "app.h"

#include <ctime>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

std::shared_ptr<App> App::instance;

App::App()
{
    srand(time(NULL));
    graphics = std::make_shared<Graphics>( "Ants " VERSION, WINDOW_WIDTH, WINDOW_HEIGHT );
}

void App::init()
{
    scene = std::make_shared<Scene> ( ModelPoint( FIELD_WIDTH, FIELD_HEIGHT ) );
    scene->init();
}

const std::shared_ptr<App> &App::getApp()
{
    if( !instance )
    {
        instance = std::shared_ptr<App>( new App() );
        instance->init();
    }
    return instance;
}

void App::mainCycle()
{
    while( !isQuiting )
    {
        Uint32 startProcessing = SDL_GetTicks();
        processEvents();
        action();
        draw();
        Uint32 timeProcessing = SDL_GetTicks() - startProcessing;
        Uint32 timeForFrame = (timeProcessing < DELAY)?DELAY:timeProcessing;
        scene->FPS = timeForFrame > 0 ? 1000.0 / timeForFrame
                                   : 1001.0;
        if( timeProcessing < DELAY )
            SDL_Delay( DELAY - timeProcessing );
    }
}

void App::processEvents()
{
    SDL_Event Event;
    while( SDL_PollEvent( &Event ) )
    {
        switch( Event.type )
        {
        case SDL_QUIT:
            isQuiting = true;
            break;
        case SDL_KEYDOWN:
            switch( Event.key.keysym.scancode )
            {
            case SDL_SCANCODE_Z:
                scene->resetFood();
                break;
            case SDL_SCANCODE_M:
                SDL_assert(false);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

}

void App::action()
{
    scene->action();
}

void App::draw()
{
    scene->draw();
    graphics->updateWindow();
}
