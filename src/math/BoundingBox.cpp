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

        const Vector2D &BoundingBox::getTopLeft() const
        {
            return topLeft;
        }

        const Vector2D &BoundingBox::getBottomRight() const
        {
            return bottomRight;
        }

        bool BoundingBox::intersectsWith(const BoundingBox &other) const
        {
            return topLeft.getX() <= other.bottomRight.getX() &&
                    bottomRight.getX() >= other.topLeft.getX() &&
                    topLeft.getY() <= other.bottomRight.getY() &&
                    bottomRight.getY() >= other.topLeft.getY();
        }

        bool BoundingBox::completelyIn(const BoundingBox &other) const
        {
            return topLeft.getX() >= other.topLeft.getX() &&
                    bottomRight.getX() <= other.bottomRight.getX() &&
                    topLeft.getY() >= other.topLeft.getY() &&
                    bottomRight.getY() <= other.bottomRight.getY();
        }
    }
}
