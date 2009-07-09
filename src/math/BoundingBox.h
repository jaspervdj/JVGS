#ifndef JVGS_MATH_BOUNDINGBOX_H
#define JVGS_MATH_BOUNDINGBOX_H

#include "Vector2D.h"

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

                /** Check for intersection with another bounding box.
                 *  @param other BoundingBox to check intersection with.
                 *  @return If there is any intersection of the two boxes.
                 */
                virtual bool intersectsWith(const BoundingBox &other) const;

                /** Check if this bounding box lays completely in another
                 *  bounding box.
                 *  @param other BoundingBox to lay in.
                 *  @return If this BoundingBox lays completely in the other.
                 */
                virtual bool completelyIn(const BoundingBox &other) const;
        };
    }
}

#endif
