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
        RectangleRenderer::RectangleRenderer(Rectangle *rectangle):
                PrimitiveRenderer(rectangle)
        {
            this->rectangle = rectangle;
        }

        RectangleRenderer::~RectangleRenderer()
        {
        }

        void RectangleRenderer::stroke(Renderer *renderer)
        {
            renderer->begin(Renderer::LINE_STRIP);
            vectors(renderer);
            renderer->end();
        }

        void RectangleRenderer::vectors(Renderer *renderer) const
        {
            Vector2D position = rectangle->getPosition(),
                     size = rectangle->getSize();

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
            /* Left top to close. */
            renderer->vector(position);
        }
    }
}
