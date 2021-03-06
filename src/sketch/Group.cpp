#include "Group.h"
#include "../video/VideoManager.h"

using namespace std;
using namespace jvgs::video;

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

        SketchElementType Group::getType() const
        {
            return SKETCHELEMENTTYPE_GROUP;
        }

        void Group::addSketchElement(SketchElement *sketchElement)
        {
            sketchElements.push_back(sketchElement);
        }

        int Group::getNumberOfSketchElements() const
        {
            return (int) sketchElements.size();
        }

        SketchElement *Group::getSketchElement(int index) const
        {
            return sketchElements[index];
        }

        void Group::finnish()
        {
            for(int i = 0; i < getNumberOfSketchElements(); i++) {
                sketchElements[i]->finnish();
            }
        }

        void Group::render() const
        {
            for(int i = 0; i < getNumberOfSketchElements(); i++) {
                sketchElements[i]->render();
            }
        }

        void Group::render(Renderer *renderer)
        {
            for(int i = 0; i < getNumberOfSketchElements(); i++) {
                sketchElements[i]->render(renderer);
            }
        }
    }
}
