#include "BoundingBox.h"

namespace jvgs
{
    namespace math
    {
        BoundingBox::BoundingBox(const Vector2D &topLeft,
                const Vector2D &bottomRight)
        {
            this->topLeft = topLeft;
            this->bottomRight = bottomRight;
        }

        BoundingBox::~BoundingBox()
        {
        }

        bool BoundingBox::intersectsWith(const BoundingBox &other) const
        {
            return !(topLeft.getX() > other.bottomRight.getX() ||
                     bottomRight.getX() < other.topLeft.getX() ||
                     topLeft.getY() < other.bottomRight.getY() ||
                     bottomRight.getY() < other.topLeft.getY());
        }
    }
}
