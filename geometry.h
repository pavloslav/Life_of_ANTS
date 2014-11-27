#ifndef GEOMETRY_H
#define GEOMETRY_H

#define BLOCK_SIZE    3

template< typename T >
class Point;

typedef Point<int> ScreenPoint;
typedef Point<double> ModelPoint;

template< typename T >
class Point
{
public:
  Point( T x, T y );

  inline const Point& operator += ( const Point& other );
  inline const Point& operator -= ( const Point& other );
  inline const Point& operator + () const;
  inline Point operator - () const;
  inline Point operator + ( const Point& other ) const;
  inline Point operator - ( const Point& other ) const;
  inline bool operator == ( const Point& other ) const;
  inline bool operator != ( const Point& other ) const;
  inline double abs() const;
  inline Point norm() const;
  inline double distance( const Point& other ) const;
  inline double distance2( const Point& other ) const;
  inline const Point& operator *= ( T factor );
  inline const Point& operator /= ( T divisor );
  inline Point operator * ( T factor ) const;
  inline Point operator / ( T divisor ) const;
  //inline operator ModelPoint();
  inline operator ScreenPoint() const;

private:
    int x_, y_;
};

template<>
ModelPoint::operator ScreenPoint() const
{
  return ScreenPoint( x_ * BLOCK_SIZE, y_ * BLOCK_SIZE );
}



const ModelPoint right(  1,  0 );
const ModelPoint left ( -1,  0 );
const ModelPoint up   (  0, -1 );
const ModelPoint down (  0,  1 );

template<typename T>
inline const Point<T>& Point<T>::operator += ( const Point& other )
{
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

template<typename T>
const Point<T> &Point<T>::operator -=(const Point &other)
{
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

template<typename T>
const Point<T> &Point<T>::operator +() const
{
    return *this;
}

template<typename T>
Point<T> Point<T>::operator -() const
{
    return Point( - x_, - y_ );
}

template<typename T>
Point<T> Point<T>::operator +(const Point &other) const
{
    return Point( x_ + other.x_, y_ + other.y_  );
}

template<typename T>
bool Point<T>::operator ==(const Point &other) const
{
    return ( x_ == other.x_ ) && ( y_ == other.y_ );
}

template<typename T>
bool Point<T>::operator !=(const Point &other) const
{
    return ( x_ != other.x_ ) || ( y_ != other.y_ );
}


#endif // GEOMETRY_H
