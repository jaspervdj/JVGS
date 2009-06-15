#ifndef JVGS_SKETCH_GROUPRENDERER_H
#define JVGS_SKETCH_GROUPRENDERER_H

#include "PrimitiveRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class Group;

        class GroupRenderer: public PrimitiveRenderer
        {
            private:
                Group *group;

            public:
                GroupRenderer(Group *group);
                virtual ~GroupRenderer();

                virtual void render();
        };
    }
}

#endif
