#include <ctime>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#include "scene.h"
#include "block.h"
#include "graphics.h"

#define VERSION "0.010"

using namespace std;

int main(void)
{
    //треба буде створити окремий клас гри, який створюється з меню, але поки меню нема, буде тут
    srand(time(NULL));
    SDL_SetMainReady();

    Graphics gr( "Ants " VERSION, WINDOW_WIDTH, WINDOW_HEIGHT );

    Block::mainScene = new Scene( &gr );
    while( !Block::mainScene->quit )
    {
        Block::mainScene->processEvents();
        Block::mainScene->action();
        Block::mainScene->draw();
        SDL_Delay(50);
    }
    delete Block::mainScene;
    return 0;
}
