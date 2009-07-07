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
                Vector2D &collision, float &time)
        {
            LineSegment *closest = 0;

            Vector2D position = toEllipseSpace * entity->getPosition(),
                     velocity = toEllipseSpace * entity->getVelocity();

            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {

                LineSegment *segment = *iterator;
                Line line = segment->getLine();
                float nvel = line.getNormal() * velocity;
                
                /* TODO: Special case: nvel == 0.0f */

                /* Collision times. */
                float t0 = (1.0f - line.getSignedDistance(position)) / nvel;
                float t1 = (-1.0f - line.getSignedDistance(position)) / nvel;

                /* Find first valid collision. */
                if(t0 < 0.0f || t0 > ms)
                    t0 = t1;
                if(t1 < 0.0f || t1 > ms)
                    t1 = t0;
                float t = t1 < t0 ? t1 : t0;

                Vector2D lineCollision = position - line.getNormal() +
                        velocity * t;

                /* A valid collision occurs, and is the first. */
                if(t >= 0.0f && t <= ms &&
                        segment->isInSegment(lineCollision)) {
                //if(t >= 0.0f && t <= ms) {
                    if(closest == 0 || time < t) {
                        closest = segment;
                        collision = fromEllipseSpace * lineCollision;
                        time = t;
                    }
                }
            }

            return closest;
        }
    }
}
