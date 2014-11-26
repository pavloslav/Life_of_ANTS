#include "label.h"

#include <cstring>

#include "app.h"

Label::Label( TTF_Font *font,
              int x,
              int y,
              Color col,
              const std::string &string)
              :
    font_ ( font ),
    color( col ),
    surface( NULL ),
    texture( NULL ),
    changed( false )
{
    if( string != "" )
    {
        content << string;
        changed = true;
    }
    else
    {
        sourceRect.x = 0;
        sourceRect.y = 0;
        sourceRect.w = 0;
        sourceRect.h = 0;
        targetRect.h = 0;
        targetRect.w = 0;
    }
    targetRect.x = x;
    targetRect.y = y;
}

Label::~Label()
{
    if( surface )
        SDL_FreeSurface( surface );
    if( texture )
        SDL_DestroyTexture( texture );
}

void Label::draw()
{
    createTexture();
    SDL_RenderCopy( App::getApp()->getGraphics()->renderer, texture, &sourceRect, &targetRect );
}

void Label::createTexture()
{
    if( changed )
    {
        if( surface != NULL )
        {
            SDL_FreeSurface( surface );
        }
        char buffer[256];
        strncpy( buffer, getText().c_str(), 256 );
        surface = TTF_RenderText_Blended( font_, buffer, color );
        SDL_assert( surface != NULL );

        if( texture != NULL)
        {
            SDL_DestroyTexture( texture );
        }
        texture = SDL_CreateTextureFromSurface(  App::getApp()->getGraphics()->renderer, surface );
        SDL_assert( texture != NULL );

        SDL_GetClipRect( surface, &sourceRect );
        targetRect.w = sourceRect.w - sourceRect.x;
        targetRect.h = sourceRect.h - sourceRect.y;
    }
    changed = false;
}

const SDL_Rect& Label::getRect()
{
    createTexture();
    return targetRect;
}

void Label::setX( int x )
{
    targetRect.x = x;
}

int Label::getX() const
{
    return targetRect.x;
}

void Label::setY( int y )
{
    targetRect.y = y;
}

int Label::getY() const
{
    return targetRect.y;
}

void Label::setXY( int x, int y )
{
    targetRect.x = x;
    targetRect.y = y;
}

int Label::getHeight()
{
    createTexture();
    return targetRect.h;
}

int Label::getWidth()
{
    createTexture();
    return targetRect.w;
}

std::string Label::getText()
{
    return content.str();
}

Label& Label::setText(const std::string &string)
{
    content.str( std::string() );
    content << string;
    changed = true;
    return *this;
}


