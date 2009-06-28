#include "Ellipse.h"

namespace jvgs
{
    namespace math
    {
        Ellipse::Ellipse(float xRadius, float yRadius)
        {
            this->xRadius = xRadius;
            this->yRadius = yRadius;
        }

        Ellipse::~Ellipse()
        {
        }
    }
}
