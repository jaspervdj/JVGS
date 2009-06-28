#include "Ellipse.h"

namespace jvgs
{
    namespace math
    {
        Ellipse::Ellipse(Vector2D radius)
        {
            this->radius = radius;
        }

        Ellipse::~Ellipse()
        {
        }

        const Vector2D &Ellipse::getRadius() const
        {
            return radius;
        }
    }
}
