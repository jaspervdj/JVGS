#include "GroupRenderer.h"
#include "Group.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../core/LogManager.h"
using namespace jvgs::core;

namespace jvgs
{
    namespace sketch
    {
        GroupRenderer::GroupRenderer(Group *group)
        {
            this->group = group;
        }

        GroupRenderer::~GroupRenderer()
        {
        }

        void GroupRenderer::render()
        {
            VideoManager *videoManager = VideoManager::getInstance();

            for(int i=0; i<group->getNumberOfPrimitives(); i++) {
                Primitive *primitive = group->getPrimitive(i);

                videoManager->push();
                videoManager->transform(primitive->getMatrix());

                PrimitiveRenderer *renderer = primitive->createPrimitiveRenderer();
                renderer->render();

                videoManager->pop();

                delete renderer;
            }
        }
    }
}
