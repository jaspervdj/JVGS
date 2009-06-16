#include "PrimitiveRenderer.h"
#include "Primitive.h"
#include "StyleMap.h"

#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        PrimitiveRenderer::PrimitiveRenderer(Primitive *primitive):
                SketchElementRenderer(primitive)
        {
            this->primitive = primitive;
        }

        PrimitiveRenderer::~PrimitiveRenderer()
        {
        }

        void PrimitiveRenderer::render()
        {
            Renderer *renderer = new Renderer();

            VideoManager *videoManager = VideoManager::getInstance();
            StyleMap *styleMap = primitive->getStyleMap();

            if(styleMap->getValue("fill") != "none") {
                Color color = styleMap->getValueAsColor("fill");
                color.setAlpha(styleMap->getValueAsFloat("opacity") *
                        styleMap->getValueAsFloat("fill-opacity"));
                videoManager->setColor(color);

                fill(renderer);
            }

            if(styleMap->getValue("stroke") != "none") {
                Color color = styleMap->getValueAsColor("stroke");
                color.setAlpha(styleMap->getValueAsFloat("opacity") *
                        styleMap->getValueAsFloat("stroke-opacity"));
                videoManager->setColor(color);

                stroke(renderer);
            }

            delete renderer;
        }
    }
}
