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
                Vector2D start, end;

            public:
                /** Creates a new line.
                 *  @param start Start point of the line.
                 *  @param end End point of the line.
                 */
                LineSegment(const Vector2D &start, const Vector2D &end);

                /** Destructor.
                 */ 
                virtual ~LineSegment();

                /** Get the start point of this line segment.
                 *  @return the start point of this line segment.
                 */
                virtual const Vector2D &getStart() const;

                /** Get the end point of this line segment.
                 *  @return the end point of this line segment.
                 */
                virtual const Vector2D &getEnd() const;

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
