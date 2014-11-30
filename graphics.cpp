#include "graphics.h"

Graphics::Graphics( const char *title, int width, int height ) :
    error( 0 ),
    window( NULL ),
    renderer( NULL )
{
    int initResult = SDL_Init( SDL_INIT_VIDEO );
    SDL_assert( initResult >= 0 );

    window = SDL_CreateWindow( title,
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               width, height,
                               0 );
    SDL_assert( window != NULL );

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    SDL_assert( renderer != NULL );

    int ttfInitResult = TTF_Init();
    SDL_assert( ttfInitResult >= 0 );

    font = TTF_OpenFont("times.ttf", 24);
    SDL_assert( font != NULL );

    smallFont = TTF_OpenFont("times.ttf", 8);
    SDL_assert( font != NULL );

}

Graphics::~Graphics()
{
    TTF_Quit();
    SDL_Quit();
}

void Graphics::setColor( const Color &color )
{
    SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
}

void Graphics::updateWindow()
{
    SDL_RenderPresent( renderer );
}

Color::Color( Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha )
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
