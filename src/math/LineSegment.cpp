#include "LineSegment.h"

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace math
    {
        LineSegment::LineSegment(const Vector2D &start, const Vector2D &end)
        {
            this->start = start;
            this->end = end;
        }

        LineSegment::~LineSegment()
        {
        }

        const Vector2D &LineSegment::getStart() const
        {
            return start;
        }

        const Vector2D &LineSegment::getEnd() const
        {
            return end;
        }

        Line LineSegment::getLine() const
        {
            return Line(start, end - start);
        }

        float LineSegment::getLength() const
        {
            return start.getDistance(end);
        }

        Vector2D LineSegment::getPoint(float t) const
        {
            return start * (1.0f - t) + end * t;
        }
    }
}
