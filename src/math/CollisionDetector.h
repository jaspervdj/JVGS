#ifndef JVGS_MATH_COLLISIONDETECTOR_H
#define JVGS_MATH_COLLISIONDETECTOR_H

#include "../sketch/Sketch.h"
#include "../sketch/Path.h"
#include "Vector2D.h"
#include <vector>

namespace jvgs
{
    namespace math
    {
        class BoundedObject;
        class MathManager;
        class QuadTree;
        class LineSegment;

        class CollisionDetector
        {
            private:
                /** The objects to collide with. */
                std::vector<BoundedObject*> objects;

                /** Tree to speed stuff up. */
                QuadTree *tree;

                /** MathManager to perform calculations. */
                MathManager *mathManager;

            public:
                /** Constructor.
                 *  @param sketch Sketch with lines to collide against.
                 */
                CollisionDetector(sketch::Sketch *sketch);

                /** Destructor.
                 */
                virtual ~CollisionDetector();

                /** Get the first point at which the entity will collide
                 *  with the world.
                 *  @param radius Radius of the entity.
                 *  @param position Initial position of the entity.
                 *  @param velocity Velocity of the entity.
                 *  @param time Will contain the exact collision time.
                 *  @param collision Will contain the exact collision point.
                 *  @return If there is a collision.
                 */
                virtual bool getClosestCollision(const Vector2D &radius,
                        const Vector2D &position, const Vector2D &velocity,
                        float *time, Vector2D *collision);

            protected:
                /** Add lines from a sketch group.
                 *  @param group Group to add the lines from.
                 */
                virtual void addLinesFromGroup(sketch::Group *group);

                /** Divide a path into lines and add the lines
                 *  to this selector.
                 *  @param path Path to add the lines from.
                 */
                virtual void addLinesFromPath(sketch::Path *path);

                /** Get the first point at which an entity will collide
                 *  with a segment.
                 *  @param segment LineSegment to check collision against.
                 *  @param position Initial position of the entity.
                 *  @param velocity Initial velocity of the entity.
                 *  @param time Will contain the exact collision time.
                 *  @param collision Will contain the exact collision point.
                 *  @return If the entity collided with the segment.
                 */
                virtual bool getClosestCollision(LineSegment *segment,
                        const Vector2D &position, const Vector2D &velocity,
                        float *time, Vector2D *collision) const;

                /** Checks if a collision occurs between a moving unit circle
                 *  and a point.
                 *  @param position Initial position of the unit circle.
                 *  @param velocity Velocity of the unit circle.
                 *  @param point Point to check collision against.
                 *  @param treshold Check only the time frame before treshold.
                 *  @param time Will contain the exact collision time.
                 *  @param collision Will contain the exact collision point.
                 *  @return If there was a collision.
                 */
                bool pointCollision(const Vector2D &position,
                        const Vector2D &velocity, const Vector2D &point,
                        float treshold, float *time, Vector2D *collision) const;

                /** Convert a vector to ellipse space.
                 *  @param radius Radius of the ellipse.
                 *  @param v Vector to convert.
                 *  @return Result of the conversion.
                 */
                Vector2D toEllipseSpace(const Vector2D &radius,
                        const Vector2D &v) const;

                /** Convert a vector from ellipse space.
                 *  @param radius Radius of the ellipse.
                 *  @param v Vector to convert.
                 *  @return Result of the conversion.
                 */
                Vector2D fromEllipseSpace(const Vector2D &radius,
                        const Vector2D &v) const;
        };
    }
}

#endif
