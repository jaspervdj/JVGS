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
                Path();
                virtual ~Path();

                virtual int getNumberOfPoints();
                virtual math::Vector2D getPoint(int index);
        };
    }
}
#endif
