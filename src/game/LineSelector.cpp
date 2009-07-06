#include "LineSelector.h"

#include <iostream>
#include "../sketch/PathComponent.h"
#include "../math/PathSegment.h"
#include "../math/Vector2D.h"
using namespace jvgs::sketch;
using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace game
    {
        LineSelector::LineSelector(Sketch *sketch)
        {
            Group *root = sketch->getRoot();
            addLinesFromGroup(root);
            cout << "Added " << segments.size() << " line segments." << endl;
        }

        LineSelector::~LineSelector()
        {
            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {
                delete (*iterator);
            }
        }

        void LineSelector::addLinesFromGroup(Group *group)
        {
            for(int i = 0; i < group->getNumberOfSketchElements(); i++) {
                SketchElement *element = group->getSketchElement(i);
                if(element->getType() == SketchElement::GROUP)
                    addLinesFromGroup((Group*) element);
                else if(element->getType() == SketchElement::PATH)
                    addLinesFromPath((Path*) element);
            }
        }

        void LineSelector::addLinesFromPath(Path *path)
        {
            for(int i = 0; i < path->getNumberOfComponents(); i++) {
                PathComponent *component = path->getComponent(i);
                for(int j = 0; j < component->getNumberOfSegments(); j++) {
                    PathSegment *segment = component->getSegment(j);
                    float increment = 5.0f / segment->getLength();
                    Vector2D previous = segment->getPoint(0.0f), current;
                    for(float t = increment; t <= 1.0f; t += increment) {
                        current = segment->getPoint(t);
                        segments.push_back(new LineSegment(current, previous));
                        previous = current; 
                    }
                }
            }
        }
    }
}
