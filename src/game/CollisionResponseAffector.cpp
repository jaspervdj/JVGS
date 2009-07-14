#include "CollisionResponseAffector.h"
#include "Entity.h"

#include "../sketch/PathComponent.h"
using namespace jvgs::sketch;

#include "../math/PathSegment.h"
#include "../math/BoundingBox.h"
#include "../math/Vector2D.h"
#include "../math/Line.h"
using namespace jvgs::math;

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        const float CollisionResponseAffector::VERY_CLOSE;
        const float CollisionResponseAffector::SLIP_COSINE;
        const int CollisionResponseAffector::MAX_STEPS;

        CollisionResponseAffector::CollisionResponseAffector(Entity *entity,
                Sketch *sketch, const math::Vector2D &gravity): Affector(entity)
        {
            toEllipseSpace = AffineTransformationMatrix();
            toEllipseSpace.scale(entity->getEllipse().inverted());

            fromEllipseSpace = AffineTransformationMatrix();
            fromEllipseSpace.scale(entity->getEllipse());

            Group *root = sketch->getRoot();
            addLinesFromGroup(root);

            tree = new SegmentQuadTree(&segments);
            mathManager = MathManager::getInstance();

            this->gravity = gravity;
        }

        CollisionResponseAffector::~CollisionResponseAffector()
        {
            delete tree;
            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {
                delete (*iterator);
            }
        }

        int CollisionResponseAffector::getPriority() const
        {
            /* Very low priority. */
            return 1;
        }

        void CollisionResponseAffector::affect(float ms)
        {
            /* Store the original ms. */
            float originalMs = ms;

            /* Convert vectors to ellipse space. */
            Vector2D position = toEllipseSpace * getEntity()->getPosition();
            Vector2D velocity = toEllipseSpace * getEntity()->getVelocity();
            Vector2D destination;

            int collisionSteps = 0;
            while(collisionSteps < MAX_STEPS && ms > 0) {

                /* Update destination. */
                destination = position + velocity * ms;

                Vector2D collision;
                float time;
                float distance;
                LineSegment *segment = closestCollision(ms, position, velocity,
                        &collision, &time, &distance);

                /* No collision, just update position. */
                if(!segment) {
                    position = destination;
                    ms = 0;

                /* A collision occurred. */
                } else {

                    Vector2D newPosition = position;

                    /* Only update above a certain distance. */
                    if(distance >= VERY_CLOSE) {
                        Vector2D v = velocity;
                        v.setLength(distance - VERY_CLOSE);
                        newPosition = position + v;

                        /* Adjust collision point a little. */
                        collision -= v.normalized() * VERY_CLOSE;
                    }

                    /* Line going through the position and the collision point.
                     * This line's normal determines the sliding line. */
                    Line collisionLine(position, collision - position);
                    Line slidingLine = Line(collision,
                            collisionLine.getNormal());

                    /* Calculate new velocity. */
                    destination = destination - slidingLine.getNormal() * 
                            slidingLine.getSignedDistance(destination);
                    velocity = destination - collision;


                    /* Update the time and position. */
                    position = newPosition;
                    ms -= time;
                }

                /* Keep track of the steps. */
                collisionSteps++;
            }

            /* Now set the entity's position. */
            getEntity()->setPosition(fromEllipseSpace * position);

            if(collisionSteps >= MAX_STEPS) {
                /* When we go over MAX_STEPS chances are we're probably bouncing
                 * against a wall, or getting stuck in some corner. Best is to
                 * set velocity to 0 now. */
                velocity = Vector2D(0.0f, 0.0f);
            }

            /* We check if we can fall down. */
            Vector2D collision;
            float time;
            float distance;
            float msToFall = 2.0f * VERY_CLOSE / gravity.getLength();
            LineSegment *segment = closestCollision(msToFall, position, gravity,
                        &collision, &time, &distance);
            bool canFall = false;
            /* We can fall if we aren't blocked. */
            if(!segment) {
                canFall = true;
            /* Check if we can slip on the segment. */
            } else {
                /* segment->getLine().getVector.getLength() is 1 so we leave
                 * that out. */
                float cosine = segment->getLine().getVector() * gravity /
                    gravity.getLength();
                canFall = cosine > SLIP_COSINE || cosine < -SLIP_COSINE;
            }

            /* Fall. */
            if(canFall)
                velocity += gravity * originalMs;

            /* Set the entity's velocity. */
            getEntity()->setVelocity(fromEllipseSpace * velocity);
            velocity = fromEllipseSpace * velocity;
        }

        LineSegment *CollisionResponseAffector::closestCollision(float ms,
                const Vector2D &position, const Vector2D &velocity,
                Vector2D *collision, float *time, float *distance)
        {
            LineSegment *closest = 0;

            Vector2D destination = position + velocity * ms;
            BoundingBox boundingBox(
                    BoundingBox(position - Vector2D(1.0f, 1.0f),
                    position + Vector2D(1.0f, 1.0f)),
                    BoundingBox(destination - Vector2D(1.0f, 1.0f),
                    destination + Vector2D(1.0f, 1.0f)));

            /* The result from the tree search. */
            /* TODO When there are multiple calls in one frame, it will
             * calculate the result every time. We don't want that. */
            vector<LineSegment*> result;
            tree->findSegments(&boundingBox, &result);

            /* Loop over all lines to find closest collision. */
            for(vector<LineSegment*>::iterator iterator = result.begin();
                    iterator != result.end(); iterator++) {

                /* Get the line segment. */
                LineSegment *segment = *iterator;

                /* Temporary result variables. */
                Vector2D tmpCollision;
                float tmpTime;

                /* Check against single segment. */
                if(closestCollision(segment, ms, position, velocity,
                        &tmpCollision, &tmpTime)) {
                    /* If this collision is the closest, store it, erasing
                     * the previously remembered collision. */
                    if(closest == 0 || tmpTime < *time) {
                        closest = segment;
                        *collision = tmpCollision;
                        *time = tmpTime;
                        *distance = (velocity * (*time)).getLength();
                    }
                }
            }

            return closest;
        }

        void CollisionResponseAffector::addLinesFromGroup(Group *group)
        {
            for(int i = 0; i < group->getNumberOfSketchElements(); i++) {
                SketchElement *element = group->getSketchElement(i);
                if(element->getType() == SKETCHELEMENTTYPE_GROUP)
                    addLinesFromGroup((Group*) element);
                else if(element->getType() == SKETCHELEMENTTYPE_PATH)
                    addLinesFromPath((Path*) element);
            }
        }

        void CollisionResponseAffector::addLinesFromPath(Path *path)
        {
            for(int i = 0; i < path->getNumberOfComponents(); i++) {
                PathComponent *component = path->getComponent(i);
                for(int j = 0; j < component->getNumberOfSegments(); j++) {
                    PathSegment *segment = component->getSegment(j);
                    float increment = 5.0f / segment->getLength();
                    Vector2D previous = segment->getPoint(0.0f), current;
                    for(float t = increment; t <= 1.0f; t += increment) {
                        current = segment->getPoint(t);

                        /* Convert to ellipse space and add. */
                        segments.push_back(new LineSegment(
                                    toEllipseSpace * current,
                                    toEllipseSpace * previous));

                        previous = current; 
                    }
                }
            }
        }

        bool CollisionResponseAffector::closestCollision(LineSegment *segment,
                float ms, const Vector2D &position, const Vector2D &velocity,
                Vector2D *collision, float *time) const
        {
            Line line = segment->getLine();
            float normalDotVelocity = line.getNormal() * velocity;

            /* Collision times. */
            float t0, t1;
            
            /* Special case: normalDotVelocity == 0.0f */
            if(normalDotVelocity == 0.0f) {
                /* Collision. */
                if(line.getDistance(position) < 1.0f) {
                    t0 = 0.0f;
                    t1 = ms;
                } else {
                    return false;
                }
            } else {
                /* Calculate times. */
                float t0 = (1.0f - line.getSignedDistance(position)) /
                        normalDotVelocity;
                float t1 = (-1.0f - line.getSignedDistance(position)) /
                        normalDotVelocity;
            }

            /* Sort. */
            if(t0 > t1) {
                float tmp = t0;
                t0 = t1;
                t1 = tmp;
            }

            bool foundCollision = false;
            Vector2D ellipseCollision;
            *time = ms;

            /* At least one of them should be in the range. */
            if(t0 > ms || t1 < 0.0f)
                return false;

            /* Clamp to [0.0f, ms]. */
            t0 = t0 <= 0.0f ? 0.0f : t0;
            t1 = t1 <= 0.0f ? 0.0f : t1;
            t0 = t0 >= ms ? ms : t0;
            t1 = t1 >= ms ? ms : t1;

            /* Parameters for the equation. */
            float a, b, c, root;

            /* Check start. */
            foundCollision = pointCollision(position, velocity,
                    segment->getStart(), *time, &root, collision);
            if(foundCollision)
                *time = root;

            /* Check end. */
            foundCollision = pointCollision(position, velocity,
                    segment->getEnd(), *time, &root, collision);
            if(foundCollision)
                *time = root;

            /* Check line segment between start and end. */
            Vector2D edge = segment->getEnd() - segment->getStart();
            Vector2D posToStart = segment->getStart() - position;
            float edgeSquaredLength = edge.getSquaredLength();
            float edgeDotVelocity = edge * velocity;
            float edgeDotPosToStart = edge * posToStart;

            a = edgeSquaredLength * - velocity.getSquaredLength() +
                    edgeDotVelocity * edgeDotVelocity;
            b = edgeSquaredLength * (2.0f * (velocity * posToStart)) -
                    2.0f * edgeDotVelocity * edgeDotPosToStart;
            c = edgeSquaredLength *
                    (1.0f - posToStart.getSquaredLength()) +
                    edgeDotPosToStart * edgeDotPosToStart;

            /* If there is a lower solution... */
            if(mathManager->getLowestPositiveRoot(a, b, c, *time, &root)) {
                float f = (edgeDotVelocity * root - edgeDotPosToStart) /
                    edgeSquaredLength;

                /* Within the segment. */
                if(f >= 0.0 && f <= 1.0) {
                    *time = root;
                    foundCollision = true;
                    *collision = segment->getStart() + edge * f;
                }
            }

            return foundCollision;
        }

        bool CollisionResponseAffector::pointCollision(const Vector2D &position,
                const Vector2D &velocity, const Vector2D &point, float treshold,
                float *time, Vector2D *collision) const
        {
            float root;
            bool found = mathManager->getLowestPositiveRoot(
                    velocity.getSquaredLength(),
                    2.0f * (velocity * (position - point)),
                    (point - position).getSquaredLength() - 1.0f,
                    treshold, &root);

            if(found) {
                *time = root;
                *collision = point;
                return true;
            } else {
                return false;
            }
        }
    }
}
