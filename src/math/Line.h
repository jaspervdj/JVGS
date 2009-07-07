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

                /* Constant used in signed distance calculation.
                 */
                float signedDistanceConstant;

            public:
                /** vector will be normalized. */
                Line(Vector2D point, Vector2D vector);
                virtual ~Line();

                virtual const Vector2D &getPoint() const;
                virtual const Vector2D &getVector() const;
                virtual Vector2D getNormal() const;

                /** Get the closest point on this line to any point.
                 *  @param p Point to find the closest point for.
                 *  @return The point on this line, closest to p.
                 */
                virtual Vector2D getClosestPoint(const Vector2D &p) const;

                /** Get the distance to a point.
                 *  @param p Point to find the distance to.
                 *  @return The distance from this line to p.
                 */
                virtual float getDistance(const Vector2D &p) const;

                /** Get the signed distance to a point.
                 *  @param p Point to find the signed distance to.
                 *  @return The signed distance from this line to p.
                 */
                virtual float getSignedDistance(const Vector2D &p) const;
        };
    }
}

#endif
