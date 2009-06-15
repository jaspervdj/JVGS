#ifndef JVGS_VIDEO_RENDERER_H
#define JVGS_VIDEO_RENDERER_H

#include "../math/Vector2D.h"
#include <SDL/SDL_opengl.h>

namespace jvgs
{
    namespace video
    {
        class VideoManager;

        class Renderer
        {
            protected:

            public:
                Renderer();
                virtual ~Renderer();

                virtual void begin(GLuint type) const;
                virtual void end() const;

                virtual void vector(const math::Vector2D &vector) const;
        };
    };
};

#endif
