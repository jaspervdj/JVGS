#include "Line.h"

namespace jvgs
{
    namespace math
    {
        Line::Line(Vector2D point, Vector2D vector)
        {
            this->point = point;
            this->vector = vector.normalized();
            signedDistanceConstant = - (getNormal() * point);
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
            return Vector2D(-vector.getY(), vector.getX());
        }

		Vector2D Line::getClosestPoint(const Vector2D& p) const
		{
            Vector2D c = p - point;
			float t = vector * c;
			return point + vector * t;
		}

        float Line::getDistance(const Vector2D &p) const
        {
            return p.getDistance(getClosestPoint(p));
        }

        float Line::getSignedDistance(const Vector2D &p) const
        {
            return (getNormal() * p) + signedDistanceConstant;
        }
    }
}
