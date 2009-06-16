#ifndef JVGS_SKETCH_PATH_H
#define JVGS_SKETCH_PATH_H

#include "Primitive.h"

namespace jvgs
{
    namespace sketch
    {
        class Path: public Primitive
        {
            private:

            public:
                Path(SketchElement *parent);
                virtual ~Path();

                virtual int getNumberOfPoints();
                virtual math::Vector2D getPoint(int index);

                virtual SketchElementRenderer *createSketchElementRenderer();
        };
    }
}
#endif
