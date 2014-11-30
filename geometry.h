#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <algorithm>
#include <SDL2/SDL.h>


template< typename T >
class Point
{
public:
    Point( T x, T y ) : x_( x ), y_ ( y )
    {
    }

    inline const Point& operator += ( const Point& other )
    {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }

    inline const Point& operator -= ( const Point& other )
    {
        x_ -= other.x_;
        y_ -= other.y_;
        return *this;
    }

    inline const Point& operator + () const
    {
        return *this;
    }

    inline Point operator - () const
    {
        return Point( - x_, - y_ );
    }

    inline Point operator + ( const Point& other ) const
    {
        return Point( *this ) += other;
    }

    inline Point operator - ( const Point& other ) const
    {
        return Point( *this ) -= other ;
    }

    inline bool operator == ( const Point& other ) const
    {
        return ( x_ == other.x_ ) && ( y_ == other.y_ );
    }

    inline bool operator != ( const Point& other ) const
    {
        return ( x_ != other.x_ ) || ( y_ != other.y_ );
    }

    inline double abs() const
    {
        return sqrt( abs2() );
    }

    inline double abs2() const
    {
        return x_ * x_ + y_ * y_;
    }

    inline Point norm() const
    {
        return *this/abs();
    }

    inline double distance( const Point& other ) const
    {
        return (*this-other).abs();
    }

    inline double distance2( const Point& other ) const
    {
        return (*this-other).abs2();
    }

    inline const Point& operator *= ( T factor )
    {
        x_ *= factor;
        y_ *= factor;
        return *this;
    }

    inline const Point& operator /= ( T divisor )
    {
        x_ /= divisor;
        y_ /= divisor;
        return *this;
    }

    inline Point operator * ( T factor ) const
    {
        return Point( *this ) *= factor;
    }

    inline Point operator / ( T divisor ) const
    {
        return Point( *this ) /= divisor;
    }

    template< typename U>
    operator Point<U>() const;

    operator SDL_Point() const;
    inline T getX() const
    {
        return x_;
    }

    inline T getY() const
    {
        return y_;
    }

    static double horizontalCoefficent, verticalCoefficent;
    static const Point zero, up, down, left, right;

private:
    T x_, y_;
};

typedef Point<int> ScreenPoint;
typedef Point<double> ModelPoint;


template< typename T >
class Rectangle
{
public:
    Point<T> topLeft, size;
    Rectangle( const Point<T>& location, const Point<T>& dimentions )
        : topLeft( location ), size( dimentions )
    {
    }
    inline operator SDL_Rect() const;
    inline Point<T> projection( Point<T> p)
    {
        return Point<T> ( std::min( std::max ( p.getX(), topLeft.getX() ),
                               topLeft.getX() + size.getX() ),
                          std::min( std::max ( p.getY(), topLeft.getY() ),
                               topLeft.getY() + size.getY() ) );
    }
};


typedef Rectangle<int> ScreenRectangle;
typedef Rectangle<double> ModelRectangle;




#endif // GEOMETRY_H
