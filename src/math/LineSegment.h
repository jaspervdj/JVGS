#ifndef JVGS_MATH_LINESEGMENT_H
#define JVGS_MATH_LINESEGMENT_H

#include "Line.h"
#include "Vector2D.h"

namespace jvgs
{
    namespace math
    {
        class LineSegment
        {
            private:
                /* The start and end of the line. */
                Vector2D p1, p2;

            public:
                /** Creates a new line.
                 *  @param p1 Start point of the line.
                 *  @param p2 End point of the line.
                 */
                LineSegment(const Vector2D &p1, const Vector2D &p2);

                /** Destructor.
                 */ 
                virtual ~LineSegment();

                /** Get the line this segment is a part of.
                 *  @return The line this segment lays on.
                 */
                virtual Line getLine() const;

                /** Get the length of this line segment.
                 *  @return The length of this line segment.
                 */
                virtual float getLength() const;

                /** Get a given point on the line segment.
                 *  @param t A value between 0.0 and 1.0
                 *  @return A point on the line.
                 */
                virtual Vector2D getPoint(float t) const;
        };
    }
}

#endif
