#ifndef JVGS_SKETCH_PRIMITIVE_H
#define JVGS_SKETCH_PRIMITIVE_H

#include "../video/Color.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"

namespace jvgs
{
    namespace sketch
    {
        class PrimitiveRenderer;
        class StyleMap;

        class Primitive
        {
            private:
                Primitive *parent;
                StyleMap *styleMap;

                math::AffineTransformationMatrix matrix;

            public:
                Primitive(Primitive *parent);
                virtual ~Primitive();

                virtual Primitive *getParent() const;
                virtual StyleMap *getStyleMap() const;

                virtual void setMatrix(
                        const math::AffineTransformationMatrix &matrix);

                virtual const math::AffineTransformationMatrix &getMatrix()
                        const;

                virtual PrimitiveRenderer *createPrimitiveRenderer() = 0;
        };
    }
}

#endif
