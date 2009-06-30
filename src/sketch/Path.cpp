#include "Path.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

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
        }
    }
}
