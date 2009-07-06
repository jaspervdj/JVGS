#ifndef JVGS_MATH_ELLIPSE_H
#define JVGS_MATH_ELLIPSE_H

#include "Vector2D.h"

namespace jvgs
{
    namespace math
    {
        class Ellipse: public Vector2D
        {
            public:
                Ellipse(float x = 0, float y = 0);
                virtual ~Ellipse();
        };
    }
}

#endif
