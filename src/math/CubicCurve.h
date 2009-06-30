#ifndef JVGS_MATH_CUBICCURVE_H
#define JVGS_MATH_CUBICCURVE_H

#include "PathSegment.h"

namespace jvgs
{
    namespace math
    {
        class CubicCurve: public PathSegment
        {
            private:
                /** Defining points of the curve.
                 */
                Vector2D start, control1, control2, end;

                /** The curve length. An approximation, calculated in
                 *  the constructor. */
                float length;

            public:
                /** Constructor.
                 *  @param start Curve start.
                 *  @param control1 First control point.
                 *  @param control2 Second control point.
                 *  @param end End of the curve.
                 */
                CubicCurve(const Vector2D &start, const Vector2D &control1,
                        const Vector2D &control2, const Vector2D &end);

                /** Destructor.
                 */
                virtual ~CubicCurve();

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
