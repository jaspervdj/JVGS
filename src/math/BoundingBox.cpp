#include "BoundingBox.h"
#include "MathManager.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

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

        BoundingBox::BoundingBox(vector<Vector2D> *points)
        {
            MathManager *mathManager = MathManager::getInstance();
            if(points->size() >= 2) {
                vector<Vector2D>::iterator iterator = points->begin();
                Vector2D first = *iterator;
                iterator++;
                Vector2D second = *iterator;

                topLeft = Vector2D(mathManager->min<float>(first.getX(),
                        second.getX()),
                        mathManager->min<float>(first.getY(), second.getY()));
                bottomRight = Vector2D(mathManager->max<float>(
                        first.getX(), second.getX()),
                        mathManager->max<float>(first.getY(), second.getY()));

                /* Expand. */
                for(iterator = points->begin(); iterator != points->end();
                        iterator++) {
                    Vector2D point = *iterator;
                    if(point.getX() < topLeft.getX())
                        topLeft.setX(point.getX());
                    if(point.getX() > bottomRight.getX())
                        bottomRight.setX(point.getX());
                    if(point.getY() < topLeft.getY())
                        topLeft.setY(point.getY());
                    if(point.getY() > bottomRight.getY())
                        bottomRight.setY(point.getY());
                }
            } else {
                LogManager::getInstance()->warning(
                        "Boundingbox based on < 2 points."); 
            }
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

        bool BoundingBox::intersectsWith(BoundingBox *other, const Vector2D
                &vel1, const Vector2D &vel2) const
        {
            /* Trivial check. */
            if(intersectsWith(other))
                return true;

            /* Reference to do some math. */
            MathManager *mathManager = MathManager::getInstance();

            /* Relative movement. Consider this object static, and other as
             * moving. */
            Vector2D velocity = vel2 - vel1;
            float t0, t1, tMinX, tMaxX, tMinY, tMaxY;

            /* X intersection times.  */
            if(velocity.getX() == 0.0f) {
                t0 = (bottomRight.getX() - other->topLeft.getX()) /
                        velocity.getX();
                t1 = (topLeft.getX() - other->bottomRight.getX()) /
                        velocity.getX();
                tMinX = mathManager->min<float>(t0, t1);
                tMaxX = mathManager->max<float>(t0, t1);
            } else {
                if(topLeft.getX() < other->bottomRight.getX() &&
                        bottomRight.getX() > other->topLeft.getX()) {
                    tMinX = 0.0f;
                    tMaxX = 1.0f;
                } else {
                    return false;
                }
            }

            /* Some trivial rejections. */
            if(tMaxX < 0.0f)
                return false;
            if(tMinX > 1.0f)
                return false;

            /* Y intersection times. */
            if(velocity.getY() == 0.0f) {
                t0 = (bottomRight.getY() - other->topLeft.getY()) /
                        velocity.getY();
                t1 = (topLeft.getY() - other->bottomRight.getY()) /
                        velocity.getY();
                tMinY = mathManager->min<float>(t0, t1);
                tMaxY = mathManager->max<float>(t0, t1);
            } else {
                if(topLeft.getY() < other->bottomRight.getY() &&
                        bottomRight.getY() > other->topLeft.getY()) {
                    tMinY = 0.0f;
                    tMaxY = 1.0f;
                } else {
                    return false;
                }
            }

            /* Some trivial rejections. */
            if(tMaxY < 0.0f)
                return false;
            if(tMinY > 1.0f)
                return false;

            /* Reject. */
            if(tMaxX < tMinY)
                return false;
            if(tMinX > tMaxY)
                return false;

            float exact = mathManager->min<float>(tMinX, tMinY);
            return exact >= 0.0f && exact <= 1.0f;
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
