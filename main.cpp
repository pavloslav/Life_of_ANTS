#include <ctime>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#include "scene.h"
#include "block.h"
#include "graphics.h"

#define VERSION "0.012"

using namespace std;

int main(void)
{
    //треба буде створити окремий клас гри, який створюється з меню, але поки меню нема, буде тут
    srand(time(NULL));
    SDL_SetMainReady();

    Graphics gr( "Ants " VERSION, WINDOW_WIDTH, WINDOW_HEIGHT );

    new Scene( &gr, FIELD_WIDTH, FIELD_HEIGHT );
    SDL_assert_release( Block::mainScene != NULL );
    while( !Block::mainScene->quit )
    {
        Uint32 startProcessing = SDL_GetTicks();
        Block::mainScene->processEvents();
        Block::mainScene->action();
        Block::mainScene->draw();
        Uint32 timeProcessing = SDL_GetTicks() - startProcessing;
        if( timeProcessing < 50 )
            SDL_Delay(50 - timeProcessing);
    }
    delete Block::mainScene;
    return 0;
}
