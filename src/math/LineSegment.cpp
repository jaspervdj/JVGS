#include "LineSegment.h"

#include <cstdlib>

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

        bool LineSegment::isInSegment(const Vector2D &point) const
        {
            float minX, maxX, minY, maxY;

            minX = start.getX() < end.getX() ? start.getX() : end.getX();
            maxX = start.getX() > end.getX() ? start.getX() : end.getX();

            minY = start.getY() < end.getY() ? start.getY() : end.getY();
            maxY = start.getY() > end.getY() ? start.getY() : end.getY();

            return point.getX() >= minX && point.getX() <= maxX &&
                    point.getY() >= minY && point.getY() <= maxY;
        }
    }
}
