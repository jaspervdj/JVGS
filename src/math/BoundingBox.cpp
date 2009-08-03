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

        bool BoundingBox::hasPoint(const Vector2D &point) const
        {
            if(point.getX() < topLeft.getX())
                return false;
            if(point.getX() > bottomRight.getX())
                return false;
            if(point.getY() < topLeft.getY())
                return false;
            if(point.getY() > bottomRight.getY())
                return false;
            return true;
        }

        bool BoundingBox::intersectsWith(BoundingBox *other) const
        {
            if(topLeft.getX() > other->bottomRight.getX())
                return false;
            if(bottomRight.getX() < other->topLeft.getX())
                return false;
            if(topLeft.getY() > other->bottomRight.getY())
                return false;
            if(bottomRight.getY() < other->topLeft.getY())
                return false;
            return true;
        }

        bool BoundingBox::completelyIn(BoundingBox *other) const
        {
            return topLeft.getX() >= other->topLeft.getX() &&
                    bottomRight.getX() <= other->bottomRight.getX() &&
                    topLeft.getY() >= other->topLeft.getY() &&
                    bottomRight.getY() <= other->bottomRight.getY();
        }
    }
}
