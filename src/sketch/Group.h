#ifndef JVGS_SKETCH_GROUP_H
#define JVGS_SKETCH_GROUP_H

#include "Primitive.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class Group: public Primitive
        {
            private:
                std::vector<Primitive*> primitives;

            public:
                Group(Primitive *parent);
                virtual ~Group();

                virtual void addPrimitive(Primitive *primitive);
                virtual int getNumberOfPrimitives() const;
                virtual Primitive *getPrimitive(int index) const;

                virtual PrimitiveRenderer *createPrimitiveRenderer();
        };
    }
}

#endif
