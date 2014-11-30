#include "geometry.h"

template<>
template<>
Point<double>::operator Point<int>() const
{
  return Point<int>( x_ * horizontalCoefficent, y_ * verticalCoefficent );
}

template<>
ScreenRectangle::operator SDL_Rect() const
{
    SDL_Rect result;
    result.x = topLeft.getX();
    result.y = topLeft.getY();
    result.w = size.getX();
    result.h = size.getY();
    return result;
}

template<>
ScreenPoint::operator SDL_Point() const
{
    SDL_Point result;
    result.x = getX();
    result.y = getY();
    return result;
}

template<>
ModelPoint::operator SDL_Point() const
{
    return ScreenPoint( *this );
}

template<>
double ModelPoint::horizontalCoefficent = 3.0;

template<>
double ModelPoint::verticalCoefficent   = 3.0;

template<>
const ModelPoint ModelPoint::zero (  0,  0);

template<>
const ModelPoint ModelPoint::up   (  0, -1);

template<>
const ModelPoint ModelPoint::down (  0,  1);

template<>
const ModelPoint ModelPoint::left ( -1,  0);

template<>
const ModelPoint ModelPoint::right(  1,  0);

template<>
const ScreenPoint ScreenPoint::zero (  0,  0);

template<>
const ScreenPoint ScreenPoint::up   (  0, -1);

template<>
const ScreenPoint ScreenPoint::down (  0,  1);

template<>
const ScreenPoint ScreenPoint::left ( -1,  0);

template<>
const ScreenPoint ScreenPoint::right(  1,  0);
