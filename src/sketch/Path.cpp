#include "Path.h"
#include "PathComponent.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        Path::Path(SketchElement *parent): SketchElement(parent)
        {
        }

        Path::~Path()
        {
            for(vector<PathComponent*>::iterator iterator = components.begin();
                    iterator != components.end(); iterator++)
                delete (*iterator);
        }

        int Path::getNumberOfComponents() const
        {
            return components.size();
        }

        PathComponent *Path::getComponent(int index) const
        {
            return components[index];
        }

        void Path::addComponent(PathComponent *component)
        {
            components.push_back(component);
        }

        void Path::render(Renderer *renderer) const
        {
            for(int i = 0; i < getNumberOfComponents(); i++) {
                PathComponent *component = getComponent(i);

                renderer->begin(Renderer::LINE_STRIP);
                for(int j = 0; j < component->getNumberOfSegments(); j++) {
                    PathSegment *segment = component->getSegment(j);
                    float increment = 5.0f / segment->getLength();

                    for(float t = 0.0f; t <= 1.0f; t += increment) {
                        renderer->vector(segment->getPoint(t));
                    }
                }

                renderer->end();
            }
        }
    }
}
