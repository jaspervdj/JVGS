#ifndef JVGS_GAME_COLLISIONRESPONDER_H
#define JVGS_GAME_COLLISIONRESPONDER_H

#include "../sketch/Sketch.h"
#include "../sketch/Group.h"
#include "../sketch/Path.h"
#include "../math/LineSegment.h"
#include "../math/Vector2D.h"
#include "../math/MathManager.h"
#include "../math/AffineTransformationMatrix.h"
#include "../math/SegmentQuadTree.h"
#include "Affector.h"
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
        class CollisionResponseAffector: public Affector
        {
            private:
                const static float VERY_CLOSE = 0.001;
                const static int MAX_STEPS = 10;

                Entity *entity;

                math::AffineTransformationMatrix toEllipseSpace,
                        fromEllipseSpace;

                /** Keep the position, velocity and destination of the entity in
                 *  ellipse space. */
                math::Vector2D position, velocity, destination;

                /** Segments in ellipse space. */
                std::vector<math::LineSegment*> segments;

                /** A tree to speed stuff up. */
                math::SegmentQuadTree *tree;

                /** MathManager to perform calculations. */
                math::MathManager *mathManager;

            public:
                /** Constructor.
                 *  @param entity Entity to respond to collisions.
                 *  @param sketch Sketch width lines to collide against.
                 */
                CollisionResponseAffector(Entity *entity,
                        sketch::Sketch *sketch);

                /** Destructor.
                 */
                virtual ~CollisionResponseAffector();

                /* Override.
                 */
                int getPriority() const;

                /* Override.
                 */
                virtual void affect(float ms);

                /** Get the first point at which the entity will collide
                 *  with the world.
                 *  @param ms Milliseconds the entity can be moved.
                 *  @param collision Will contain the exact collision point.
                 *  @param time Will contain the exact collision time.
                 *  @param distance Will contain he distance to the collison.
                 *  @return The LineSegment the entity collided with.
                 */
                virtual math::LineSegment *closestCollision(float ms,
                        math::Vector2D *collision, float *time,
                        float *distance);

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
                 *  @param collision Will contain the exact collision point.
                 *  @param time Will contain the exact collision time.
                 *  @return If the entity collided with the segment.
                 */
                virtual bool closestCollision(math::LineSegment *segment,
                        float ms, math::Vector2D *collision, float *time) const;

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
