#ifndef JVGS_MATH_LINE_H
#define JVGS_MATH_LINE_H

#include "Vector2D.h"

namespace jvgs
{
    namespace math
    {
        class Line
        {
            private:
                /* A point on the line. */
                Vector2D point;

                /* Vector so that for any point p on the line
                 * p = point + r * vector
                 */
                Vector2D vector;

            public:
                /** vector will be normalized. */
                Line(Vector2D point, Vector2D vector);
                virtual ~Line();

                virtual Vector2D getNormal() const;
        };
    }
}

#endif
