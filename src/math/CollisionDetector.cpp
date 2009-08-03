#include "CollisionDetector.h"
#include "BoundingBox.h"
#include "QuadTree.h"
#include "LineSegment.h"
#include "MathManager.h"

#include "../sketch/PathComponent.h"
#include "../sketch/Group.h"
using namespace jvgs::sketch;

using namespace std;

namespace jvgs
{
    namespace math
    {
        CollisionDetector::CollisionDetector(Sketch *sketch)
        {
            Group *root = sketch->getRoot();
            addLinesFromGroup(root);

            tree = new QuadTree(&objects);
            mathManager = MathManager::getInstance();
        }

        CollisionDetector::~CollisionDetector()
        {
            delete tree;
            for(vector<BoundedObject*>::iterator iterator = objects.begin();
                    iterator != objects.end(); iterator++) {
                delete (*iterator);
            }
        }

        bool CollisionDetector::getClosestCollision(
                const Vector2D &radius, const Vector2D &position,
                const Vector2D &velocity, float *time, Vector2D *collision)
        {
            bool hasCollision = false;

            Vector2D ePosition = toEllipseSpace(radius, position);
            Vector2D eVelocity = toEllipseSpace(radius, velocity);

            Vector2D destination = position + velocity;
            BoundingBox boundingBox(
                    BoundingBox(position - radius,
                    position + radius),
                    BoundingBox(destination - radius,
                    destination + radius));

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

                /* Convert the segment to ellipse space. */
                LineSegment *eSegment = new LineSegment(
                        toEllipseSpace(radius, segment->getStart()),
                        toEllipseSpace(radius, segment->getEnd()));

                /* Temporary result variables. */
                Vector2D tmpCollision;
                float tmpTime;

                /* Check against single segment. */
                if(getClosestCollision(eSegment, ePosition, eVelocity,
                        &tmpTime, &tmpCollision)) {
                    /* If this collision is the closest, store it, erasing
                     * the previously remembered collision. */
                    if(!hasCollision || tmpTime < *time) {
                        hasCollision = true;
                        *collision = fromEllipseSpace(radius, tmpCollision);
                        *time = tmpTime;
                    }
                }

                /* Delete the ellipse space segment. */
                delete eSegment;
            }

            return hasCollision;
        }

        void CollisionDetector::addLinesFromGroup(Group *group)
        {
            for(int i = 0; i < group->getNumberOfSketchElements(); i++) {
                SketchElement *element = group->getSketchElement(i);
                if(element->getType() == SKETCHELEMENTTYPE_GROUP)
                    addLinesFromGroup((Group*) element);
                else if(element->getType() == SKETCHELEMENTTYPE_PATH)
                    addLinesFromPath((Path*) element);
            }
        }

        void CollisionDetector::addLinesFromPath(Path *path)
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
                        objects.push_back(new LineSegment(current, previous));
                        previous = current; 
                    }

                    /* Last segment for sure. */
                    objects.push_back(new LineSegment(previous, 
                                segment->getPoint(1.0f)));
                }
            }
        }

        bool CollisionDetector::getClosestCollision(LineSegment *segment,
                const Vector2D &position, const Vector2D &velocity,
                float *time, Vector2D *collision) const
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

        bool CollisionDetector::pointCollision(
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

        Vector2D CollisionDetector::toEllipseSpace(const Vector2D &radius,
                const Vector2D &v) const
        {
            return Vector2D(v.getX() / radius.getX(), v.getY() / radius.getY());
        }

        Vector2D CollisionDetector::fromEllipseSpace(const Vector2D &radius,
                const Vector2D &v) const
        {
            return Vector2D(v.getX() * radius.getX(), v.getY() * radius.getY());
        }
    }
}
