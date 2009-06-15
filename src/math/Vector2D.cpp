#include "Vector2D.h"
#include <cmath>

namespace jvgs
{
    namespace math
    {
        Vector2D::Vector2D( float _x, float _y ): x(_x), y(_y)
        {
        }

        Vector2D::Vector2D( const Vector2D &other ): x(other.x), y(other.y)
        {
        }

        Vector2D::~Vector2D()
        {
        }

        float Vector2D::getX() const
        {
            return x;
        }

        void Vector2D::setX( const float &x )
        {
            this->x = x;
        }

        float Vector2D::getY() const
        {
            return y;
        }

        void Vector2D::setY( const float &y )
        {
            this->y = y;
        }

        const Vector2D &Vector2D::operator=(const Vector2D &other )
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        const Vector2D Vector2D::operator+( const Vector2D &other ) const
        {
            return Vector2D( x + other.x, y + other.y );
        }

        const Vector2D &Vector2D::operator+=( const Vector2D &other )
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        const Vector2D Vector2D::operator-( const Vector2D &other ) const
        {
            return Vector2D( x - other.x, y - other.y );
        }

        const Vector2D &Vector2D::operator-=( const Vector2D &other )
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        const Vector2D Vector2D::operator*( const float &scalar ) const
        {
            return Vector2D( x * scalar, y * scalar );
        }

        const Vector2D &Vector2D::operator*=( const float &scalar )
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        const Vector2D Vector2D::operator/( const float &scalar ) const
        {
            return Vector2D( x / scalar, y / scalar );
        }

        const Vector2D &Vector2D::operator/=( const float &scalar )
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        float Vector2D::dotProduct() const
        {
            return x * x + y * y;
        }

        float Vector2D::length() const
        {
            return sqrt( dotProduct() );
        }

        float Vector2D::distance( const Vector2D &other ) const
        {
            return sqrt( (x - other.x) * (x - other.x) +
                         (y - other.y) * (y - other.y) );
        }
    };
};
