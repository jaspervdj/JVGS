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

        class Primitive
        {
            private:
                bool stroke;
                video::Color strokeColor;

                bool fill;
                video::Color fillColor;

                math::AffineTransformationMatrix matrix;

            public:
                Primitive();
                virtual ~Primitive();

                virtual void setStroke(bool stroke);
                virtual bool hasStroke() const;

                virtual void setStrokeColor(const video::Color &color);
                virtual video::Color getStrokeColor() const;

                virtual void setFill(bool fill);
                virtual bool hasFill() const;

                virtual void setFillColor(const video::Color &color);
                virtual video::Color getFillColor() const;

                virtual void setMatrix(const math::AffineTransformationMatrix &matrix);
                virtual const math::AffineTransformationMatrix &getMatrix() const;

                virtual PrimitiveRenderer *createPrimitiveRenderer() = 0;
        };
    }
}

#endif
