#include "CollisionResponsePositioner.h"
#include "Entity.h"

#include "../input/InputManager.h"
using namespace jvgs::input;

#include "../sketch/PathComponent.h"
using namespace jvgs::sketch;

#include "../math/PathSegment.h"
#include "../math/BoundingBox.h"
#include "../math/Vector2D.h"
#include "../math/Line.h"
#include "../math/QuadTree.h"
using namespace jvgs::math;

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        const float CollisionResponsePositioner::VERY_CLOSE;
        const int CollisionResponsePositioner::MAX_STEPS;
        const float CollisionResponsePositioner::SLIP_LIMIT;

        CollisionResponsePositioner::CollisionResponsePositioner(Entity *entity,
                Sketch *sketch, const math::Vector2D &gravity):
                Positioner(entity)
        {
            toEllipseSpace = AffineTransformationMatrix();
            toEllipseSpace.scale(entity->getEllipse().inverted());

            fromEllipseSpace = AffineTransformationMatrix();
            fromEllipseSpace.scale(entity->getEllipse());

            Group *root = sketch->getRoot();
            addLinesFromGroup(root);

            tree = new QuadTree(&objects);
            mathManager = MathManager::getInstance();

            this->gravity = toEllipseSpace * gravity;
        }

        CollisionResponsePositioner::~CollisionResponsePositioner()
        {
            delete tree;
            for(vector<BoundedObject*>::iterator iterator = objects.begin();
                    iterator != objects.end(); iterator++) {
                delete (*iterator);
            }
        }

        void CollisionResponsePositioner::affect(float ms)
        {
            /* Store the original ms. */
            float timeLeft = 1.0f;

            /* Convert vectors to ellipse space. */
            Vector2D position = toEllipseSpace * getEntity()->getPosition();
            Vector2D velocity = (toEllipseSpace * getEntity()->getVelocity()) *
                    ms;
            Vector2D destination;

            Vector2D collision;
            if(hasNearCollision(ms, &collision)) {
                Vector2D fall = collision - position;
                float cosine = (gravity * fall) /
                        (gravity.getLength() * fall.getLength());
                if(cosine < 1.0f - SLIP_LIMIT || cosine > 1.0f + SLIP_LIMIT)
                    velocity += gravity * ms;
            } else {
                velocity += gravity * ms;
            }

            int collisionSteps = 0;
            while(collisionSteps < MAX_STEPS && timeLeft > 0 &&
                    velocity.getLength() > VERY_CLOSE) {

                /* Update destination. */
                destination = position + velocity;

                float time;
                float distance;
                LineSegment *segment = closestCollision(position, velocity,
                        &collision, &time, &distance);

                /* No collision, just update position. */
                if(!segment) {
                    position = destination;
                    timeLeft = 0.0f;

                /* A collision occurred. */
                } else {
                    Vector2D newPosition = position;

                    /* Only update above a certain distance. */
                    if(distance >= VERY_CLOSE) {
                        Vector2D v = velocity;
                        v.setLength(distance - VERY_CLOSE);
                        newPosition = position + v;
                    }

                    /* Subtract used velocity. */
                    velocity -= (position - collision);

                    /* Add a normal force. */
                    Vector2D normalForce = position - collision;
                    normalForce.setLength(velocity.getLength());
                    velocity += normalForce;
 
                    /* Update the time and position. */
                    position = newPosition;
                    timeLeft -= time;
                }

                /* Keep track of the steps. */
                collisionSteps++;
            }

            /* Now set the entity's position. */
            getEntity()->setPosition(fromEllipseSpace * position);
        }

        LineSegment *CollisionResponsePositioner::closestCollision(
                const Vector2D &position, const Vector2D &velocity,
                Vector2D *collision, float *time, float *distance)
        {
            LineSegment *closest = 0;

            Vector2D destination = position + velocity;
            BoundingBox boundingBox(
                    BoundingBox(position - Vector2D(1.0f, 1.0f),
                    position + Vector2D(1.0f, 1.0f)),
                    BoundingBox(destination - Vector2D(1.0f, 1.0f),
                    destination + Vector2D(1.0f, 1.0f)));

            /* The result from the tree search. */
            /* TODO When there are multiple calls in one frame, it will
             * calculate the result every time. We don't want that. */
            vector<BoundedObject*> result;
            tree->findObjects(&boundingBox, &result);

            /* Loop over all lines to find closest collision. */
            for(vector<BoundedObject*>::iterator iterator = result.begin();
                    iterator != result.end(); iterator++) {

                /* Get the line segment. */
                LineSegment *segment = (LineSegment*) *iterator;

                /* Temporary result variables. */
                Vector2D tmpCollision;
                float tmpTime;

                /* Check against single segment. */
                if(closestCollision(segment, position, velocity,
                        &tmpCollision, &tmpTime)) {
                    /* If this collision is the closest, store it, erasing
                     * the previously remembered collision. */
                    if(closest == 0 || tmpTime < *time) {
                        closest = segment;
                        *collision = tmpCollision;
                        *time = tmpTime;
                        *distance = (*time) * velocity.getLength();
                    }
                }
            }

            return closest;
        }

        bool CollisionResponsePositioner::hasNearCollision(float ms,
                Vector2D *collision)
        {
            float time, distance;
            Vector2D position = toEllipseSpace * getEntity()->getPosition();
            LineSegment *segment = closestCollision(position, gravity * ms,
                    collision, &time, &distance);

            return segment != 0;
        }

        Vector2D CollisionResponsePositioner::getGravity() const
        {
            return fromEllipseSpace * gravity;
        }

        void CollisionResponsePositioner::addLinesFromGroup(Group *group)
        {
            for(int i = 0; i < group->getNumberOfSketchElements(); i++) {
                SketchElement *element = group->getSketchElement(i);
                if(element->getType() == SKETCHELEMENTTYPE_GROUP)
                    addLinesFromGroup((Group*) element);
                else if(element->getType() == SKETCHELEMENTTYPE_PATH)
                    addLinesFromPath((Path*) element);
            }
        }

        void CollisionResponsePositioner::addLinesFromPath(Path *path)
        {
            for(int i = 0; i < path->getNumberOfComponents(); i++) {
                PathComponent *component = path->getComponent(i);
                for(int j = 0; j < component->getNumberOfSegments(); j++) {
                    PathSegment *segment = component->getSegment(j);
                    float increment = Path::getSubdivideLength() /
                            segment->getLength();
                    Vector2D previous = segment->getPoint(0.0f), current;
                    for(float t = increment; t <= 1.0f; t += increment) {
                        current = segment->getPoint(t);

                        /* Convert to ellipse space and add. */
                        objects.push_back(new LineSegment(
                                    toEllipseSpace * current,
                                    toEllipseSpace * previous));

                        previous = current; 
                    }

                    /* Last segment for sure. */
                    objects.push_back(new LineSegment(
                                toEllipseSpace * previous,
                                toEllipseSpace * segment->getPoint(1.0f)));
                }
            }
        }

        bool CollisionResponsePositioner::closestCollision(LineSegment *segment,
                const Vector2D &position, const Vector2D &velocity,
                Vector2D *collision, float *time) const
        {
            Line line = segment->getLine();
            float signedDistanceToLine = line.getSignedDistance(position);
            float normalDotVelocity = line.getNormal() * velocity;

            /* Collision times. */
            float t0, t1;
            bool embeddedInLine = false;
            
            /* Special case: normalDotVelocity == 0.0f */
            if(normalDotVelocity == 0.0f) {
                /* Collision. */
                if(line.getDistance(position) < 1.0f) {
                    t0 = 0.0f;
                    t1 = 1.0f;
                    embeddedInLine = true;
                } else {
                    return false;
                }
            } else {
                /* Calculate times. */
                t0 = (1.0f - signedDistanceToLine) / normalDotVelocity;
                t1 = (-1.0f - signedDistanceToLine) / normalDotVelocity;

                /* Sort. */
                if(t0 > t1) {
                    float tmp = t0;
                    t0 = t1;
                    t1 = tmp;
                }

                /* Check that at least one result is within range. */
                if(t0 > 1.0f || t1 < 0.0f)
                    return false;

                /* Clamp to [0, 1] */
                t0 = mathManager->clamp(t0, 0.0f, 1.0f);
                t1 = mathManager->clamp(t1, 0.0f, 1.0f);
            }

            /* Will contain the solution of the equation. */
            bool foundCollision = false;
            *time = 1.0f;
            float root;

            /* Check start. */
            if(pointCollision(position, velocity, segment->getStart(), *time,
                    &root, collision)) {
                foundCollision = true;
                *time = root;
            }

            /* Check end. */
            if(pointCollision(position, velocity, segment->getEnd(), *time,
                    &root, collision)) {
                foundCollision = true;
                *time = root;
            }

            /* Check line segment between start and end. */
            BoundingBox *segmentBox = segment->getBoundingBox();
            Vector2D collisionPoint =
                    line.getClosestPoint(position + velocity * t0);
            if(segmentBox->hasPoint(collisionPoint) && t0 <= *time
                    && t0 >= 0.0f) {
                *time = t0;
                foundCollision = true;
                *collision = collisionPoint;
            } else {
                collisionPoint =
                        line.getClosestPoint(position + velocity * t1);
                if(segmentBox->hasPoint(collisionPoint) && t1 <= *time
                    && t1 >= 0.0f) {
                    *time = t1;
                    foundCollision = true;
                    *collision = collisionPoint;
                }
            }

            return foundCollision;
        }

        bool CollisionResponsePositioner::pointCollision(
                const Vector2D &position, const Vector2D &velocity,
                const Vector2D &point, float treshold, float *time,
                Vector2D *collision) const
        {
            float root;
            if(mathManager->getLowestPositiveRoot(velocity.getSquaredLength(),
                    2.0f * (velocity * (position - point)),
                    (point - position).getSquaredLength() - 1.0f, treshold,
                    &root)) {
                *time = root;
                *collision = point;
                return true;
            } else {
                return false;
            }
        }
    }
}
