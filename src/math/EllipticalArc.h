#ifndef JVGS_MATH_ELLIPTICALARC_H
#define JVGS_MATH_ELLIPTICALARC_H

#include "Curve.h"

namespace jvgs
{
    namespace math
    {
        class EllipticalArc: public Curve
        {
            private:
                /** Ellipse center. */
                Vector2D center;

                /** Rotation of x axis. */
                float phi;

                /** Radius. */
                Vector2D radius;

                /** Start angle. */
                float theta1;

                /** Angle delta. */
                float deltaTheta;

            public:
                /** Constructor.
                 *  @param start Start point of the arc.
                 *  @param radius Radius of the ellipse.
                 *  @param phi Rotation of x axis.
                 *  @param largeArc Large arc flag.
                 *  @param sweep Sweep flag.
                 *  @param end End point of the arc.
                 */
                EllipticalArc(const Vector2D &start, const Vector2D &radius,
                        float phi, bool largeArc, bool sweep,
                        const Vector2D &end);

                /** Destructor.
                 */
                virtual ~EllipticalArc();

                /* Override
                 */
                 Vector2D getPoint(float t) const;

            protected:
                /* Override
                 */
                 virtual float getLengthGuess() const;
        };
    }
}

#endif
