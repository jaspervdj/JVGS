#include "Group.h"
#include "GroupRenderer.h"

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        Group::Group(SketchElement *parent): SketchElement(parent)
        {
        }

        Group::~Group()
        {
            vector<SketchElement*>::iterator iterator = sketchElements.begin();
            while (iterator != sketchElements.end()) {
                delete (*iterator);
                iterator++;
            }
        }

        void Group::addSketchElement(SketchElement *sketchElement)
        {
            sketchElements.push_back(sketchElement);
        }

        int Group::getNumberOfSketchElements() const
        {
            return sketchElements.size();
        }

        SketchElement *Group::getSketchElement(int index) const
        {
            return sketchElements[index];
        }

        SketchElementRenderer *Group::createSketchElementRenderer()
        {
            return new GroupRenderer(this);
        }
    }
}
