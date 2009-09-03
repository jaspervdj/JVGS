#ifndef JVGS_MATH_BOUNDINGBOX_H
#define JVGS_MATH_BOUNDINGBOX_H

#include "Vector2D.h"
#include <vector>

namespace jvgs
{
    namespace math
    {
        class BoundingBox
        {
            private:
                Vector2D topLeft, bottomRight;

            public:
                /** Constructor.
                 *  @param topLeft Top left of the bounding box.
                 *  @param bottomRight Bottom right of the bounding box.
                 */
                BoundingBox(const Vector2D &topLeft = Vector2D(),
                        const Vector2D &bottomRight = Vector2D());

                /** Constructor. Create the smallest bounding box fitting
                 *  around a number of points.
                 *  @param points Vectors to fit around.
                 */
                BoundingBox(std::vector<Vector2D> *points);

                /** Constructor. Join two bounding boxes so we get a bounding
                 *  box containing both bounding boxes.
                 *  @param b1 First bounding box.
                 *  @param b2 Second bounding box.
                 */
                BoundingBox(const BoundingBox &b1, const BoundingBox &b2);

                /** Destructor.
                 */
                virtual ~BoundingBox();

                /** Get the top left point.
                 *  @return The top left point.
                 */
                virtual const Vector2D &getTopLeft() const;

                /** Get the bottom right point.
                 *  @return The bottom right point.
                 */
                virtual const Vector2D &getBottomRight() const;

                /** Checks if a given point lies inside this bounding box.
                 *  @param point Point to check.
                 *  @return If this point lies inside this bounding box.
                 */
                virtual bool hasPoint(const Vector2D &point) const;

                /** Check for intersection with another bounding box.
                 *  @param other BoundingBox to check intersection with.
                 *  @return If there is any intersection of the two boxes.
                 */
                virtual bool intersectsWith(BoundingBox *other,
                        const Vector2D &vel1, const Vector2D &vel2) const;

                /** Check for intersection with another bounding box.
                 *  @param other BoundingBox to check intersection with.
                 *  @param vel1 Velocity of this bounding box.
                 *  @param vel2 Velocity of the other bounding box.
                 *  @return If there is an intersection of the boxes.
                 */
                virtual bool intersectsWith(BoundingBox *other) const;

                /** Check if this bounding box lays completely in another
                 *  bounding box.
                 *  @param other BoundingBox to lay in.
                 *  @return If this BoundingBox lays completely in the other.
                 */
                virtual bool completelyIn(BoundingBox *other) const;
        };
    }
}

#endif
