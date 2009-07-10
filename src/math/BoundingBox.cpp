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

        BoundingBox::BoundingBox(const BoundingBox &b1, const BoundingBox &b2)
        {
            topLeft.setX(b1.topLeft.getX() < b2.topLeft.getX() ?
                    b1.topLeft.getX() : b2.topLeft.getX());
            bottomRight.setX(b1.bottomRight.getX() > b2.bottomRight.getX() ?
                    b1.bottomRight.getX() : b2.bottomRight.getX());

            topLeft.setY(b1.topLeft.getY() < b2.topLeft.getY() ?
                    b1.topLeft.getY() : b2.topLeft.getY());
            bottomRight.setY(b1.bottomRight.getY() > b2.bottomRight.getY() ?
                    b1.bottomRight.getY() : b2.bottomRight.getY());
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
