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
        const float Path::SUBDIVIDE_LENGTH;

        Path::Path(SketchElement *parent): SketchElement(parent)
        {
        }

        Path::~Path()
        {
            for(vector<PathComponent*>::iterator iterator = components.begin();
                    iterator != components.end(); iterator++)
                delete (*iterator);
        }

        SketchElementType Path::getType() const
        {
            return SKETCHELEMENTTYPE_PATH;
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
                getComponent(i)->render(renderer);
            }
        }
    }
}
