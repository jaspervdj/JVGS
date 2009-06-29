#ifndef JVGS_MATH_PATHSEGMENT_H
#define JVGS_MATH_PATHSEGMENT_H

#include "Vector2D.h"

namespace jvgs
{
    namespace math
    {
        class PathSegment
        {
            private:
            public:
                PathSegment();
                virtual ~PathSegment();

                /** Get the length of this line segment.
                 *  @return The length of this line segment.
                 */
                virtual float getLength() const = 0;

                /** Get a given point on the line segment.
                 *  @param t A value between 0.0 and 1.0
                 *  @return A point on the line.
                 */
                virtual Vector2D getPoint(float t) const = 0;
        };
    }
}

#endif
