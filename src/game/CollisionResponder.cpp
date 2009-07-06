#include "CollisionResponder.h"
#include "Entity.h"

#include <iostream>
using namespace std;

#include "../sketch/PathComponent.h"
using namespace jvgs::sketch;

#include "../math/PathSegment.h"
#include "../math/Vector2D.h"
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
            Vector2D position = toEllipseSpace * entity->getPosition(),
                     velocity = toEllipseSpace * entity->getVelocity();

            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {
            }
        }
    }
}
