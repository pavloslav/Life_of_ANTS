#ifndef LABEL_H
#define LABEL_H


#include <sstream>
#include "graphics.h"

class Label
{
public:
    Label( Graphics *graph, int x, int y, Color col, const char *string = NULL );
    ~Label();

    void draw();
    void setX( int x );
    int getX() const;
    void setY( int y );
    int getY() const;
    void setXY( int x, int y );
    int getHeight();
    int getWidth();
    const SDL_Rect& getRect();
    std::string getText();

    Label &setText( const char *string );

    template<typename T>
    Label& operator <<( const T& t );

private:
    void createTexture();
    void calculateRects();

    Graphics *graphics;
    Color color;
    std::stringstream content;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect sourceRect, targetRect;
};

template< typename T >
Label& Label::operator <<(const T &t)
{
    content << t;
    createTexture();
    return *this;
}

#endif // LABEL_H
