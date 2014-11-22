#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define FIELD_WIDTH   200
#define FIELD_HEIGHT  200
#define BLOCK_SIZE    3
#define HEADER_SIZE   50
#define WINDOW_WIDTH  ( BLOCK_SIZE * FIELD_WIDTH )
#define WINDOW_HEIGHT ( HEADER_SIZE + ( BLOCK_SIZE * FIELD_HEIGHT ) )

class Graphics
{
public:
    Graphics(const char *title, int width, int height);
    ~Graphics();
    static SDL_Point point( float x, float y );
    static SDL_Rect rect(float x, float y, float w , float h);

    int error;
    SDL_Window* window;
    SDL_Renderer* canvas;
    TTF_Font* font;
};

#endif // GRAPHICS_H
