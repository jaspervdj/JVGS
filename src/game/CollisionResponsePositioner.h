#ifndef JVGS_GAME_COLLISIONRESPONSEPOSITIONER_H
#define JVGS_GAME_COLLISIONRESPONSEPOSITIONER_H

#include "../sketch/Sketch.h"
#include "../sketch/Group.h"
#include "../sketch/Path.h"
#include "../math/LineSegment.h"
#include "../math/Vector2D.h"
#include "../math/MathManager.h"
#include "../math/AffineTransformationMatrix.h"
#include "../math/SegmentQuadTree.h"
#include "Positioner.h"
#include <vector>

namespace jvgs
{
    namespace game
    {
        class LineSelector;
        class Entity;

        /** This class is NOT THREAD SAFE AT ALL, due to some
         *  optimizations.
         */
        class CollisionResponsePositioner: public Positioner
        {
            private:
#               ifndef SWIG
                    const static float VERY_CLOSE = 0.001;
                    /** The entity will slip on a segment when the cosine of
                     *  the angle between the gravity vector and the segment
                     *  direction is larger than this. */
                    const static float SLIP_COSINE = 0.154;
                    const static int MAX_STEPS = 10;
#               else
                    static float VERY_CLOSE = 0.001;
                    static float SLIP_COSINE = 0.154;
                    static int MAX_STEPS = 10;
#               endif

                Entity *entity;

                math::AffineTransformationMatrix toEllipseSpace,
                        fromEllipseSpace;

                /** The segments in ellpise space. */
                std::vector<math::LineSegment*> segments;

                /** Tree to speed stuff up. */
                math::SegmentQuadTree *tree;

                /** MathManager to perform calculations. */
                math::MathManager *mathManager;

                /** Gravity pulling the entity. */
                math::Vector2D gravity;

            public:
                /** Constructor.
                 *  @param entity Entity to respond to collisions.
                 *  @param sketch Sketch width lines to collide against.
                 *  @param gravity Gravity pulling the entity.
                 */
                CollisionResponsePositioner(Entity *entity,
                        sketch::Sketch *sketch,
                        const math::Vector2D &gravity);

                /** Destructor.
                 */
                virtual ~CollisionResponsePositioner();

                /* Override.
                 */
                virtual void affect(float ms);

                /** Get the first point at which the entity will collide
                 *  with the world.
                 *  @param ms Milliseconds the entity can be moved.
                 *  @param position Initial position of the entity.
                 *  @param velocity Initial velocity of the entity.
                 *  @param collision Will contain the exact collision point.
                 *  @param time Will contain the exact collision time.
                 *  @param distance Will contain he distance to the collison.
                 *  @return The LineSegment the entity collided with.
                 */
                virtual math::LineSegment *closestCollision(float ms,
                        const math::Vector2D &position,
                        const math::Vector2D &velocity,
                        math::Vector2D *collision, float *time,
                        float *distance);

                /* Override
                 */
                virtual bool canJump(float ms);

                /* Override
                 */
                virtual math::Vector2D getGravity() const;

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

                /** Get the first point at which the entity will collide
                 *  with a segment. This function assumes position and
                 *  velocity are set correctly.
                 *  @param segment LineSegment to check collision against.
                 *  @param ms Milliseconds the entity can be moved.
                 *  @param position Initial position of the entity.
                 *  @param velocity Initial velocity of the entity.
                 *  @param collision Will contain the exact collision point.
                 *  @param time Will contain the exact collision time.
                 *  @return If the entity collided with the segment.
                 */
                virtual bool closestCollision(math::LineSegment *segment,
                        float ms, const math::Vector2D &position,
                        const math::Vector2D &velocity,
                        math::Vector2D *collision, float *time) const;

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
                bool pointCollision(const math::Vector2D &position,
                        const math::Vector2D &velocity,
                        const math::Vector2D &point, float treshold,
                        float *time, math::Vector2D *collision) const;
        };
    }
}

#endif
