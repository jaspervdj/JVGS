#ifndef JVGS_MATH_AFFINETRANSFORMATIONMATRIX_H
#define JVGS_MATH_AFFINETRANSFORMATIONMATRIX_H

#include "Matrix.h"

namespace jvgs
{
    namespace math
    {
        class AffineTransformationMatrix: public Matrix
        {
            private:
            public:
                AffineTransformationMatrix();
                AffineTransformationMatrix(float r0c0, float r0c1, float r0c2,
                                           float r1c0, float r1c1, float r1c2);
                virtual ~AffineTransformationMatrix();

                virtual void translate(float x, float y);
                virtual void scale(float x, float y);
                virtual void rotate(float degrees);
                virtual void rotate(float degrees, float x, float y);
                virtual void skewX(float degrees);
                virtual void skewY(float degrees);
        };
    }
}

#endif
