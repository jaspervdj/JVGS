#ifndef JVGS_VIDEO_RENDERER_H
#define JVGS_VIDEO_RENDERER_H

#include "../math/Vector2D.h"
#include <SDL/SDL_opengl.h>
#include <vector>

namespace jvgs
{
    namespace video
    {
        class VideoManager;

        /** Types of primives that can be rendered.
         */
        enum RenderType
        {
            RENDERTYPE_LINES = GL_LINES,
            RENDERTYPE_LINE_STRIP = GL_LINE_STRIP,
            RENDERTYPE_LINE_LOOP = GL_LINE_LOOP,
            RENDERTYPE_QUADS = GL_QUADS,
            RENDERTYPE_POLYGON = GL_POLYGON,
            RENDERTYPE_CONCAVE_POLYGON
        };

        /** A class to draw primitives fast.
         */
        class Renderer
        {
            protected:
                /** If we are between a begin() and an end() call.
                 */
                bool busy;

                /** Type currently rendering.
                 */
                RenderType rendering;

            public:
                /** Constructor.
                 */
                Renderer();

                /** Destructor.
                 */
                virtual ~Renderer();

                /** Start rendering a certain type of primitive.
                 *  @param type Type of the primitive to be rendered.
                 */
                virtual void begin(RenderType type);

                /** End the primitive currently being rendered.
                 */
                virtual void end();

                /** Check if we are between a begin() and an end() call.
                 */
                virtual bool isBusy() const;

                /** Add a vector to the primitive.
                 *  @param vector Vector to add to the primitive.
                 */
                virtual void vector(const math::Vector2D &vector) = 0;
        };
    };
};

#endif
