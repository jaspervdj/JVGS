#include "QuadraticCurve.h"

namespace jvgs
{
    namespace math
    {
        QuadraticCurve::QuadraticCurve(const Vector2D &start,
                const Vector2D &control, const Vector2D &end)
        {
            this->start = start;
            this->control = control;
            this->end = end;

            calculateLength();
        }

        QuadraticCurve::~QuadraticCurve()
        {
        }

        Vector2D QuadraticCurve::getPoint(float t) const
        {
            /* Create a line. */
            Vector2D v1 = start * (1.0f - t) + control * t,
                     v2 = control * (1.0f - t) + end * t;

            /* Find the point. */
            return v1 * (1.0f - t) + v2 * t;
        }

        float QuadraticCurve::getLengthGuess() const
        {
            return start.getDistance(control) + control.getDistance(end);
        }
    }
}
