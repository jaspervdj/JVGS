#ifndef JVGS_MATH_VECTOR_H
#define JVGS_MATH_VECTOR_H

namespace jvgs
{
    namespace math
    {
        /** A 2D vector that represents a point in 2D
         *  space, or a distance, or...
         */
        class Vector2D
        {
            private:
                float x, y;

            public:
                /** Constructor.
                 *  @param x X value.
                 *  @param y Y value.
                 */
                Vector2D(float x=0, float y=0);

                /** Copy constructor.
                 *  @param other Object to copy.
                 */
                Vector2D(const Vector2D &other);

                /** Destructor.
                 */
                ~Vector2D();

                float getX() const;
                void setX(const float &x);

                float getY() const;
                void setY(const float &x);

                const Vector2D &operator=(const Vector2D &other);

                const Vector2D operator+(const Vector2D &other) const;
                const Vector2D &operator+=(const Vector2D &other);

                const Vector2D operator-(const Vector2D &other) const;
                const Vector2D &operator-=(const Vector2D &other);

                const Vector2D operator*(const float &scalar) const;
                const Vector2D &operator*=(const float &scalar);

                const Vector2D operator/(const float &scalar) const;
                const Vector2D &operator/=(const float &scalar);

                /** Dot product. */
                float operator*(const Vector2D &other) const;

                float length() const;
                float distance(const Vector2D &other) const;
                Vector2D normalized() const;
                Vector2D inverted() const;

                /** Reflects the other vector around this vector and
                 *  return the result.
                 *  @param other Vector to be reflected.
                 *  @return The reflection of the parameter around this vector.
                 */
                Vector2D reflect(const Vector2D &other) const;
        };
    };
};

#endif
