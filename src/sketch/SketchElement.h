#ifndef JVGS_SKETCH_SKETCHELEMENT_H
#define JVGS_SKETCH_SKETCHELEMENT_H

#include "../video/Color.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"

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
                StyleMap *styleMap;

                math::AffineTransformationMatrix matrix;

            public:
                SketchElement(SketchElement *parent);
                virtual ~SketchElement();

                virtual SketchElement *getParent() const;
                virtual StyleMap *getStyleMap() const;

                virtual void setMatrix(
                        const math::AffineTransformationMatrix &matrix);

                virtual const math::AffineTransformationMatrix &getMatrix()
                        const;

                virtual SketchElementRenderer *createSketchElementRenderer()
                        = 0;
        };
    }
}

#endif
