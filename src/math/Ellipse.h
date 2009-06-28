#ifndef JVGS_MATH_ELLIPSE_H
#define JVGS_MATH_ELLIPSE_H

#include "Vector2D.h"

namespace jvgs
{
    namespace math
    {
        class Ellipse
        {
            private:
                Vector2D radius;

            public:
                Ellipse(Vector2D radius);
                virtual ~Ellipse();
        };
    }
}

#endif
