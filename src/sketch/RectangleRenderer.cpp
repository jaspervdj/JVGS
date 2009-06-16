#include "RectangleRenderer.h"
#include "Rectangle.h"
#include "StyleMap.h"

#include "../video/Renderer.h"
#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../math/Vector2D.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        RectangleRenderer::RectangleRenderer(Rectangle *rectangle)
        {
            this->rectangle = rectangle;
        }

        RectangleRenderer::~RectangleRenderer()
        {
        }

        void RectangleRenderer::render()
        {
            Renderer *renderer = new Renderer();

            Vector2D position = rectangle->getPosition(),
                     size = rectangle->getSize();
            StyleMap *styleMap = rectangle->getStyleMap();

            VideoManager *videoManager = VideoManager::getInstance();

            if(styleMap->getValue("fill") != "none") {
                Color color = styleMap->getValueAsColor("fill");
                color.setAlpha(styleMap->getValueAsFloat("opacity") *
                        styleMap->getValueAsFloat("fill-opacity"));
                videoManager->setColor(color);

                renderer->begin(Renderer::QUADS);
                /* Left top. */
                renderer->vector(position);
                /* Left bottom. */
                renderer->vector(Vector2D(position.getX(),
                            position.getY() + size.getY()));
                /* Right bottom */
                renderer->vector(position + size);
                /* Right top. */
                renderer->vector(Vector2D(position.getX() + size.getX(),
                            position.getY()));
                renderer->end();
            }

            if(styleMap->getValue("stroke") != "none") {
                Color color = styleMap->getValueAsColor("stroke");
                color.setAlpha(styleMap->getValueAsFloat("opacity") *
                        styleMap->getValueAsFloat("stroke-opacity"));
                videoManager->setColor(color);

                renderer->begin(Renderer::LINE_LOOP);
                /* Left top. */
                renderer->vector(position);
                /* Left bottom. */
                renderer->vector(Vector2D(position.getX(),
                            position.getY() + size.getY()));
                /* Right bottom */
                renderer->vector(position+size);
                /* Right top. */
                renderer->vector(Vector2D(position.getX() + size.getX(),
                            position.getY()));
                renderer->end();
            }

            delete renderer;
        }
    }
}
