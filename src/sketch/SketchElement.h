#ifndef JVGS_SKETCH_SKETCHELEMENT_H
#define JVGS_SKETCH_SKETCHELEMENT_H

#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
#include "../video/Renderer.h"

namespace jvgs
{
    namespace sketch
    {
        class SketchElementRenderer;
        class StyleMap;

        class SketchElement
        {
            private:
                SketchElement *parent;
                math::AffineTransformationMatrix matrix;

            public:
                SketchElement(SketchElement *parent);
                virtual ~SketchElement();

                virtual SketchElement *getParent() const;

                virtual void setMatrix(
                        const math::AffineTransformationMatrix &matrix);

                virtual const math::AffineTransformationMatrix &getMatrix()
                        const;

                virtual math::AffineTransformationMatrix getCompleteMatrix()
                        const;

                virtual void render(video::Renderer *renderer) const = 0;
        };
    }
}

#endif
