#include "food.h"
#include "block.h"
#include "scene.h"
#include "graphics.h"

Food::Food() : Block( (rand()%FIELD_WIDTH), (rand()%FIELD_HEIGHT))
{
}

void Food::draw()
{
    SDL_SetRenderDrawColor( mainScene->graphics->canvas, 0, 0, 255, 255 );
    SDL_Rect rect = Graphics::rect( getX(), getY(), 0.9, 0.9 );
    SDL_RenderDrawRect( mainScene->graphics->canvas, &rect );
}

void Food::spawn()
{
    setX((rand()%FIELD_WIDTH));
    setY((rand()%FIELD_HEIGHT));
}

