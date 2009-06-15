#ifndef JVGS_SKETCH_RECTANGLE_H
#define JVGS_SKETCH_RECTANGLE_H

#include "Primitive.h"

#include "../math/Vector2D.h"

namespace jvgs
{
    namespace sketch
    {
        class Rectangle: public Primitive
        {
            private:
                math::Vector2D position;
                math::Vector2D size;

            public:
                Rectangle(Primitive *parent);
                virtual ~Rectangle();

                virtual void setPosition(const math::Vector2D &position);
                virtual const math::Vector2D &getPosition() const;

                virtual void setSize(const math::Vector2D &size);
                virtual const math::Vector2D &getSize() const;

                virtual PrimitiveRenderer *createPrimitiveRenderer();
        };
    }
}

#endif
