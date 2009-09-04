#include "Path.h"
#include "PathComponent.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

#include "../video/SketchyRenderer.h"
#include "../video/DataRenderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        const float Path::SUBDIVIDE_LENGTH = 5.0f;

        Path::Path(SketchElement *parent): SketchElement(parent)
        {
            boundingBox = 0;
        }

        Path::~Path()
        {
            for(vector<PathComponent*>::iterator iterator = components.begin();
                    iterator != components.end(); iterator++)
                delete (*iterator);
            ListManager::getInstance()->deleteLists(list);

            if(boundingBox)
                delete boundingBox;
        }

        SketchElementType Path::getType() const
        {
            return SKETCHELEMENTTYPE_PATH;
        }

        const float &Path::getSubdivideLength()
        {
            return SUBDIVIDE_LENGTH;
        }

        int Path::getNumberOfComponents() const
        {
            return (int) components.size();
        }

        PathComponent *Path::getComponent(int index) const
        {
            return components[index];
        }

        void Path::addComponent(PathComponent *component)
        {
            components.push_back(component);
        }

        void Path::finnish()
        {
            /* Start display list. */
            ListManager *listManager = ListManager::getInstance();
            list = listManager->createLists();
            listManager->beginList(list);

            /* Fill display list. */
            Renderer *renderer = new SketchyRenderer();
            render(renderer);
            delete renderer;

            /* End display list. */
            listManager->endList();

            /* Create bounding box. */
            DataRenderer *dataRenderer = new DataRenderer();
            render(dataRenderer);
            if(dataRenderer->getData()->size() >= 2)
                boundingBox = new BoundingBox(dataRenderer->getData());
            delete dataRenderer;
        }

        void Path::render() const
        {
            ListManager::getInstance()->callList(list);
        }

        void Path::render(Renderer *renderer)
        {
            for(int i = 0; i < getNumberOfComponents(); i++) {
                getComponent(i)->render(renderer);
            }
        }

        BoundingBox *Path::getBoundingBox()
        {
            return boundingBox;
        }
    }
}
