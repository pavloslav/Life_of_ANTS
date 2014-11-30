#include "label.h"

#include <cstring>

#include "app.h"

Label::Label( TTF_Font *font,
              ScreenPoint place,
              Color col,
              const std::string &string)
              :
    font_ ( font ),
    color( col ),
    surface( NULL ),
    texture( NULL ),
    sourceRect( ScreenRectangle( ScreenPoint( 0, 0), ScreenPoint( 0, 0 ) ) ),
    targetRect( ScreenRectangle( place,              ScreenPoint( 0, 0 ) ) ),
    changed( string != "" )
{
    content << string;
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

void Label::setPlace(const ScreenPoint &point)
{
    targetRect.x = point.getX();
    targetRect.y = point.getY();
}

ScreenPoint Label::getPlace()
{
    return ScreenPoint( targetRect.x, targetRect.y );
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


