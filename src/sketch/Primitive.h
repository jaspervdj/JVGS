#ifndef JVGS_SKETCH_PRIMITIVE_H
#define JVGS_SKETCH_PRIMITIVE_H

#include "SketchElement.h"

namespace jvgs
{
    namespace sketch
    {
        class Primitive: public SketchElement
        {
            private:
            public:
                Primitive(SketchElement *parent);
                virtual ~Primitive();
        };
    }
}

#endif
