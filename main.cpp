#define SDL_MAIN_HANDLED
#include "app.h"

using namespace std;

int main(void)
{
    SDL_SetMainReady();
    App::getApp()->mainCycle();
    return 0;
}
