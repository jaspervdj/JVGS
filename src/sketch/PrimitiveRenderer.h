#ifndef JVGS_SKETCH_PRIMITIVERENDERER_H
#define JVGS_SKETCH_PRIMITIVERENDERER_H

#include "SketchElementRenderer.h"
#include "../video/Renderer.h"

namespace jvgs
{
    namespace sketch
    {
        class Primitive;

        class PrimitiveRenderer: public SketchElementRenderer
        {
            private:
                Primitive *primitive;

            public:
                PrimitiveRenderer(Primitive *primitive);
                virtual ~PrimitiveRenderer();

                virtual void render();

                virtual void fill(video::Renderer *renderer) = 0;
                virtual void stroke(video::Renderer *renderer) = 0;
        };
    }
}

#endif
