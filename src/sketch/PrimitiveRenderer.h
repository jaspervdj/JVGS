#ifndef JVGS_SKETCH_PRIMITIVERENDERER_H
#define JVGS_SKETCH_PRIMITIVERENDERER_H

namespace jvgs
{
    namespace sketch
    {
        class PrimitiveRenderer
        {
            private:
            public:
                PrimitiveRenderer();
                virtual ~PrimitiveRenderer();

                virtual void render() = 0;
        };
    }
}

#endif
