#include "colony.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>

#include "ant.h"
#include "scene.h"

Colony::Colony( Scene * scene, int r, int g, int b, int scoreX, int scoreY ) :
    mainScene( scene ),
    score( 0.0 ),
    red( r ),
    green( g ),
    blue( b ),
    scorePosX( scoreX ),
    scorePosY( scoreY )
{
}

void Colony::draw()
{
    for(unsigned int i=0;i<bases.size();++i)
    {
        bases[i]->draw();
    }
    for(unsigned int i=0;i<ants.size();++i)
    {
        ants[i]->draw();
    }
    print();
}

void Colony::print()
{
    SetSDLColor( mainScene->graphics->canvas );
    SDL_Color col;
    col.b = blue;
    col.r = red;
    col.g = green;
    std::string sc;
    std::stringstream ss;
    ss << score;
    ss >> sc;
    SDL_Surface* text=TTF_RenderText_Blended(mainScene->graphics->font,sc.c_str(),col);
    SDL_Rect src = text->clip_rect, tgt;
    tgt.x = scorePosX;
    tgt.y = scorePosY;
    tgt.h = src.h;
    tgt.w = src.w;
    SDL_Texture *texture = SDL_CreateTextureFromSurface(mainScene->graphics->canvas, text);
    SDL_assert_release( texture!= NULL );
    SDL_RenderCopy(mainScene->graphics->canvas, texture, &src, &tgt);
}

void Colony::SetSDLColor( SDL_Renderer* canvas )
{
    SDL_SetRenderDrawColor( canvas, red, green, blue, 255 );
}
