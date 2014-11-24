#include <ctime>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#include "scene.h"
#include "block.h"
#include "graphics.h"

#define VERSION "0.013"
#define DELAY   20


using namespace std;

int main(void)
{
    //треба буде створити окремий клас гри, який створюється з меню, але поки меню нема, буде тут
    srand(time(NULL));
    SDL_SetMainReady();

    auto gr = std::make_shared<Graphics>( "Ants " VERSION, WINDOW_WIDTH, WINDOW_HEIGHT );
    auto sc = std::make_shared<Scene> ( gr, FIELD_WIDTH, FIELD_HEIGHT );
    sc->init();
    while( !sc->quit )
    {
        Uint32 startProcessing = SDL_GetTicks();
        sc->processEvents();
        sc->action();
        sc->draw();
        Uint32 timeProcessing = SDL_GetTicks() - startProcessing;
        Uint32 timeForFrame = (timeProcessing < DELAY)?DELAY:timeProcessing;
        sc->FPS = timeForFrame > 0 ? 1000.0 / timeForFrame
                                  : 1001.0;
        if( timeProcessing < DELAY )
            SDL_Delay( DELAY - timeProcessing );
    }
    return 0;
}
