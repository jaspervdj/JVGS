#include "AffineTransformationMatrix.h"

#include <cmath>

namespace jvgs
{
    namespace math
    {
        AffineTransformationMatrix::AffineTransformationMatrix():
                Matrix(3, 3)
        {
        }

        AffineTransformationMatrix::AffineTransformationMatrix(
                float r0c0, float r0c1, float r0c2,
                float r1c0, float r1c1, float r1c2):
                Matrix(3, 3)
        {
            setValue(0, 0, r0c0);
            setValue(0, 1, r0c1);
            setValue(0, 2, r0c2);
            setValue(1, 0, r1c0);
            setValue(1, 1, r1c1);
            setValue(1, 2, r1c2);
        }

        AffineTransformationMatrix::~AffineTransformationMatrix()
        {
        }

        void AffineTransformationMatrix::translate(const Vector2D &vector)
        {
            *this *= AffineTransformationMatrix(1.0f, 0.0f, vector.getX(),
                                                0.0f, 1.0f, vector.getY());
        }

        void AffineTransformationMatrix::scale(const Vector2D &vector)
        {
            *this *= AffineTransformationMatrix(vector.getX(),          0.0f, 0.0f,
                                                         0.0f, vector.getY(), 0.0f);
        }

        void AffineTransformationMatrix::rotate(float degrees)
        {
            float radians = degrees * M_PI / 180.0f;
            *this *= AffineTransformationMatrix(cos(radians), -sin(radians), 0.0f,
                                                sin(radians),  cos(radians), 0.0f);
        }

        void AffineTransformationMatrix::rotate(float degrees, const Vector2D &point)
        {
            translate(point);
            rotate(degrees);
            translate(point);
        }

        void AffineTransformationMatrix::skewX(float degrees)
        {
            float radians = degrees * M_PI / 180.0f;
            *this *= AffineTransformationMatrix(1.0f, tan(radians), 0.0f,
                                                0.0f,         1.0f, 0.0f);
        }

        void AffineTransformationMatrix::skewY(float degrees)
        {
            float radians = degrees * M_PI / 180.0f;
            *this *= AffineTransformationMatrix(        1.0f, 0.0f, 0.0f,
                                                tan(radians), 1.0f, 0.0f);
        }
    }
}
