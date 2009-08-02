#ifndef JVGS_MATH_QUADRATICCURVE_H
#define JVGS_MATH_QUADRATICCURVE_H

#include "Curve.h"

namespace jvgs
{
    namespace math
    {
        class QuadraticCurve: public Curve
        {
            private:
                /** Defining points of the curve.
                 */
                Vector2D start, control, end;

            public:
                /** Constructor.
                 *  @param start Curve start.
                 *  @param control Control point.
                 *  @param end End of the curve.
                 */
                QuadraticCurve(const Vector2D &start, const Vector2D &control,
                        const Vector2D &end);

                /** Destructor.
                 */
                virtual ~QuadraticCurve();

                /* Override
                 */
                virtual Vector2D getPoint(float t) const;

                /* Override
                 */
                virtual float getLengthGuess() const;
        };
    }
}

#endif
