#include "Line.h"

namespace jvgs
{
    namespace math
    {
        Line::Line(Vector2D point, Vector2D vector)
        {
            this->point = point;
            this->vector = vector.normalized();
        }

        Line::~Line()
        {
        }

        const Vector2D &Line::getPoint() const
        {
            return point;
        }

        const Vector2D &Line::getVector() const
        {
            return vector;
        }

        Vector2D Line::getNormal() const
        {
            return Vector2D(-vector.getX(), vector.getY());
        }
    }
}
