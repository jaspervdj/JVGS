#ifndef JVGS_VIDEO_SKETCHYRENDERER_H
#define JVGS_VIDEO_SKETCHYRENDERER_H

#include "Renderer.h"
#include "../math/Noise.h"

namespace jvgs
{
    namespace video
    {
        class SketchyRenderer: public Renderer
        {
            private:
                /** Noise source. */
                math::Noise *noiseX, *noiseY;

                /** List of vectors to render. */
                std::vector<math::Vector2D> vectorList;

            public:
                /** Constructor.
                 */
                SketchyRenderer();

                /** Destructor.
                 */
                virtual ~SketchyRenderer();

                /* Override
                 */
                virtual void begin(RenderType type);

                /* Override
                 */
                virtual void end();

                /* Override
                 */
                virtual void vector(const math::Vector2D &vector);
        };
    }
}

#endif
