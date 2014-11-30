#ifndef LABEL_H
#define LABEL_H

#include <memory>
#include <sstream>
#include "graphics.h"

class Label
{
public:
    Label( TTF_Font *font, ScreenPoint place, Color col, const std::string &string = "" );
    ~Label();

    void draw();
    void setPlace(const ScreenPoint& point );;
    ScreenPoint getPlace();
    int getHeight();
    int getWidth();
    const SDL_Rect& getRect();
    std::string getText();

    Label &setText(const std::string& string );

    template<typename T>
    Label& operator <<( const T& t );

private:
    void createTexture();
    TTF_Font *font_;
    Color color;
    std::stringstream content;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect sourceRect, targetRect;
    bool changed;
};

template< typename T >
Label& Label::operator <<(const T &t)
{
    content << t;
    createTexture();
    return *this;
}

#endif // LABEL_H
