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

        void Group::render(Renderer *renderer) const
        {
            VideoManager *videoManager = VideoManager::getInstance();

            for(int i = 0; i < getNumberOfSketchElements(); i++) {
                videoManager->push();
                videoManager->transform(sketchElements[i]->getMatrix());
                sketchElements[i]->render(renderer);
                videoManager->pop();
            }
        }
    }
}
