#ifndef JVGS_SKETCH_GROUP_H
#define JVGS_SKETCH_GROUP_H

#include "SketchElement.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class StyleMap;

        class Group: public SketchElement
        {
            private:
                std::vector<SketchElement*> sketchElements;

            public:
                Group(SketchElement *parent);
                virtual ~Group();

                virtual void addSketchElement(SketchElement *sketchElement);
                virtual int getNumberOfSketchElements() const;
                virtual SketchElement *getSketchElement(int index) const;

                virtual void render(video::Renderer *renderer) const;
        };
    }
}

#endif
