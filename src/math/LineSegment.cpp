#include "LineSegment.h"

namespace jvgs
{
    namespace math
    {
        LineSegment::LineSegment(const Vector2D &p1, const Vector2D &p2)
        {
            this->p1 = p1;
            this->p2 = p2;
        }

        LineSegment::~LineSegment()
        {
        }

        Line LineSegment::getLine() const
        {
            return Line(p1, p2 - p1);
        }

        float LineSegment::getLength() const
        {
            return p1.distance(p2);
        }

        Vector2D LineSegment::getPoint(float t) const
        {
            return p1 * (1.0f - t) + p2 * t;
        }
    }
}
