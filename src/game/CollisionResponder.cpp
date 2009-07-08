#include "CollisionResponder.h"
#include "Entity.h"

#include <iostream>
using namespace std;

#include "../sketch/PathComponent.h"
using namespace jvgs::sketch;

#include "../math/PathSegment.h"
#include "../math/MathManager.h"
#include "../math/Vector2D.h"
#include "../math/Line.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        CollisionResponder::CollisionResponder(Entity *entity, Sketch *sketch)
        {
            this->entity = entity;

            toEllipseSpace = AffineTransformationMatrix();
            toEllipseSpace.scale(entity->getEllipse().inverted());

            fromEllipseSpace = AffineTransformationMatrix();
            fromEllipseSpace.scale(entity->getEllipse());

            Group *root = sketch->getRoot();
            addLinesFromGroup(root);
            cout << "Added " << segments.size() << " line segments." << endl;
        }

        CollisionResponder::~CollisionResponder()
        {
            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {
                delete (*iterator);
            }
        }

        void CollisionResponder::addLinesFromGroup(Group *group)
        {
            for(int i = 0; i < group->getNumberOfSketchElements(); i++) {
                SketchElement *element = group->getSketchElement(i);
                if(element->getType() == SketchElement::GROUP)
                    addLinesFromGroup((Group*) element);
                else if(element->getType() == SketchElement::PATH)
                    addLinesFromPath((Path*) element);
            }
        }

        void CollisionResponder::addLinesFromPath(Path *path)
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

        void CollisionResponder::update(float ms)
        {
        }

        LineSegment *CollisionResponder::closestCollision(float ms,
                Vector2D *collision, float *time)
        {
            MathManager *mathManager = MathManager::getInstance();
            LineSegment *closest = 0;

            Vector2D position = toEllipseSpace * entity->getPosition(),
                     velocity = toEllipseSpace * entity->getVelocity();

            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {

                LineSegment *segment = *iterator;
                Line line = segment->getLine();
                float normalDotVelocity = line.getNormal() * velocity;
                
                /* TODO: Special case: normalDotVelocity == 0.0f */

                /* Collision times. */
                float t0 = (1.0f - line.getSignedDistance(position)) /
                        normalDotVelocity;
                float t1 = (-1.0f - line.getSignedDistance(position)) /
                        normalDotVelocity;

                /* Sort. */
                if(t0 > t1) {
                    float tmp = t0;
                    t0 = t1;
                    t1 = tmp;
                }

                bool foundCollision = false;
                Vector2D ellipseCollision;
                float t = ms;

                /* At least one of them should be in the range. */
                if(t0 > 0.0f || t1 < ms) {

                    /* Clamp to [0.0f, ms]. */
                    t0 = t0 < 0.0f ? 0.0f : t0;
                    t1 = t1 < 0.0f ? 0.0f : t1;
                    t0 = t0 > 1.0f ? 1.0f : t0;
                    t1 = t1 > 1.0f ? 1.0f : t1;

                    /* Parameters for the equation. */
                    float a, b, c, root;

                    /* Check start. */
                    a = velocity.getSquaredLength();
                    b = 2.0f * (velocity * (position - segment->getStart()));
                    c = (segment->getStart() - position).getSquaredLength()
                            - 1.0f;
                    if(mathManager->getLowestPositiveRoot(a, b, c, t, &root)) {
                        t = root;
                        foundCollision = true;
                        ellipseCollision = segment->getStart();
                    }

                    /* Check end. */
                    a = velocity.getSquaredLength();
                    b = 2.0f * (velocity * (position - segment->getEnd()));
                    c = (segment->getEnd() - position).getSquaredLength()
                            - 1.0f;
                    if(mathManager->getLowestPositiveRoot(a, b, c, t, &root)) {
                        t = root;
                        foundCollision = true;
                        ellipseCollision = segment->getEnd();
                    }

                    /* Check line. */
                    Vector2D edge = segment->getEnd() - segment->getStart();
                    Vector2D posToStart = segment->getStart() - position;
                    float edgeSquaredLength = edge.getSquaredLength();
                    float edgeDotVelocity = edge * velocity;
                    float edgeDotPosToStart = edge * posToStart;

                    a = edgeSquaredLength * - velocity.getSquaredLength() +
                            edgeDotVelocity * edgeDotVelocity;
                    b = edgeSquaredLength * (2.0f * (velocity * posToStart)) -
                        2.0f * edgeDotVelocity * edgeDotPosToStart;
                    c = edgeSquaredLength * (1.0f - posToStart.getSquaredLength())
                        + edgeDotPosToStart * edgeDotPosToStart;

                    if(mathManager->getLowestPositiveRoot(a, b, c, t, &root)) {
                        float f = (edgeDotVelocity * root - edgeDotPosToStart) /
                            edgeSquaredLength;

                        /* Within the segment. */
                        if(f >= 0.0 && f <= 1.0) {
                            t = root;
                            foundCollision = true;
                            ellipseCollision = segment->getStart() + edge * f;
                        }
                    }
                }

                /* Find first valid collision. */
                if(foundCollision) {
                    if(closest == 0 || t < *time) {
                        closest = segment;
                        *collision = fromEllipseSpace * ellipseCollision;
                        *time = t;
                    }
                }
            }

            return closest;
        }
    }
}
