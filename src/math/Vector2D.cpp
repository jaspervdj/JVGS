#include "Vector2D.h"
#include <cmath>

namespace jvgs
{
    namespace math
    {
        Vector2D::Vector2D(float _x, float _y): x(_x), y(_y)
        {
        }

        Vector2D::Vector2D(const Vector2D &other): x(other.x), y(other.y)
        {
        }

        Vector2D::~Vector2D()
        {
        }

        float Vector2D::getX() const
        {
            return x;
        }

        void Vector2D::setX(const float &x)
        {
            this->x = x;
        }

        float Vector2D::getY() const
        {
            return y;
        }

        void Vector2D::setY(const float &y)
        {
            this->y = y;
        }

        const Vector2D &Vector2D::operator=(const Vector2D &other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        const Vector2D Vector2D::operator+(const Vector2D &other) const
        {
            return Vector2D(x + other.x, y + other.y);
        }

        const Vector2D &Vector2D::operator+=(const Vector2D &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        const Vector2D Vector2D::operator-(const Vector2D &other) const
        {
            return Vector2D(x - other.x, y - other.y);
        }

        const Vector2D &Vector2D::operator-=(const Vector2D &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        const Vector2D Vector2D::operator*(const float &scalar) const
        {
            return Vector2D(x * scalar, y * scalar);
        }

        const Vector2D &Vector2D::operator*=(const float &scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        const Vector2D Vector2D::operator/(const float &scalar) const
        {
            return Vector2D(x / scalar, y / scalar);
        }

        const Vector2D &Vector2D::operator/=(const float &scalar)
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        float Vector2D::operator*(const Vector2D &other) const
        {
            return x * other.x + y * other.y;
        }

        Vector2D Vector2D::onlyX() const
        {
            return Vector2D(x, 0.0f);
        }

        Vector2D Vector2D::onlyY() const
        {
            return Vector2D(0.0f, y);
        }

        float Vector2D::getSquaredLength() const
        {
            return (*this) * (*this);
        }

        float Vector2D::getLength() const
        {
            return sqrt(getSquaredLength());
        }

        void Vector2D::setLength(float length)
        {
            *this /= getLength();
            *this *= length;
        }

        float Vector2D::getDistance(const Vector2D &other) const
        {
            return sqrt((x - other.x) * (x - other.x) +
                        (y - other.y) * (y - other.y));
        }

        Vector2D Vector2D::normalized() const
        {
            return *this / getLength();
        }

        Vector2D Vector2D::inverted() const
        {
            return Vector2D(1.0f / x, 1.0f / y);
        }

        Vector2D Vector2D::reflect(const Vector2D &other) const
        {
            return (*this) * 2.0f - other;
        }
    };
};
