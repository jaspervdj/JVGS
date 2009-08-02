#include "CubicCurve.h"

namespace jvgs
{
    namespace math
    {
        CubicCurve::CubicCurve(const Vector2D &start, const Vector2D &control1,
                const Vector2D &control2, const Vector2D &end)
        {
            this->start = start;
            this->control1 = control1;
            this->control2 = control2;
            this->end = end;

            calculateLength();
        }

        CubicCurve::~CubicCurve()
        {
        }

        Vector2D CubicCurve::getPoint(float t) const
        {
            /* Create a triangle. */
            Vector2D u1 = start * (1.0f - t) + control1 * t,
                     u2 = control1 * (1.0f - t) + control2 * t,
                     u3 = control2 * (1.0f - t) + end * t;

            /* Create a line. */
            Vector2D v1 = u1 * (1.0f - t) + u2 * t,
                     v2 = u2 * (1.0f - t) + u3 * t;

            /* Find the point. */
            return v1 * (1.0f - t) + v2 * t;
        }

        float CubicCurve::getLengthGuess() const
        {
            return start.getDistance(control1) +
                    control1.getDistance(control2) + control2.getDistance(end);
        }
    }
}
