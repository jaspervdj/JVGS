#ifndef JVGS_VIDEO_RENDERER_H
#define JVGS_VIDEO_RENDERER_H

#include "../math/Vector2D.h"
#include <SDL/SDL_opengl.h>

namespace jvgs
{
    namespace video
    {
        class VideoManager;

        /** A class to draw primitives fast.
         */
        class Renderer
        {
            protected:

            public:
                /** Types of primives that can be rendered.
                 */
                enum Type
                {
                    LINES = GL_LINES,
                    LINE_LOOP = GL_LINE_LOOP,
                    QUADS = GL_QUADS,
                    POLYGON = GL_POLYGON
                };

                /** Constructor.
                 */
                Renderer();

                /** Destructor.
                 */
                virtual ~Renderer();

                /** Start rendering a certain type of primitive.
                 *  @param type Type of the primitive to be rendered.
                 */
                virtual void begin(Type type) const;

                /** End the primitive currently being rendered.
                 */
                virtual void end() const;

                /** Add a vector to the primitive.
                 *  @param vector Vector to add to the primitive.
                 */
                virtual void vector(const math::Vector2D &vector) const;
        };
    };
};

#endif
