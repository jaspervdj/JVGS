#include "RectangleRenderer.h"
#include "Rectangle.h"

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

            VideoManager *videoManager = VideoManager::getInstance();

            if(rectangle->hasFill()) {
                videoManager->setColor(rectangle->getFillColor());

                renderer->begin(Renderer::QUADS);
                renderer->vector(position);
                renderer->vector(Vector2D(position.getX(),position.getY()+size.getY()));
                renderer->vector(position+size);
                renderer->vector(Vector2D(position.getX()+size.getX(),position.getY()));
                renderer->end();
            }

            if(rectangle->hasStroke()) {
                videoManager->setColor(rectangle->getStrokeColor());

                renderer->begin(Renderer::LINE_LOOP);
                renderer->vector(position);
                renderer->vector(Vector2D(position.getX(),position.getY()+size.getY()));
                renderer->vector(position+size);
                renderer->vector(Vector2D(position.getX()+size.getX(),position.getY()));
                renderer->end();
            }

            delete renderer;
        }
    }
}
