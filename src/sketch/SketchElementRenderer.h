#ifndef JVGS_SKETCH_SKETCHELEMENTRENDERER_H
#define JVGS_SKETCH_SKETCHELEMENTRENDERER_H

namespace jvgs
{
    namespace sketch
    {
        class SketchElement;

        class SketchElementRenderer
        {
            private:
            public:
                SketchElementRenderer(SketchElement *element);
                virtual ~SketchElementRenderer();

                virtual void render() = 0;
        };
    }
}

#endif
