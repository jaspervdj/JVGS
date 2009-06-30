#ifndef JVGS_SKETCH_PATH_H
#define JVGS_SKETCH_PATH_H

#include "SketchElement.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class PathComponent;

        class Path: public SketchElement
        {
            private:
                std::vector<PathComponent*> components;

            public:
                Path(SketchElement *parent);
                virtual ~Path();

                virtual int getNumberOfComponents() const;
                virtual PathComponent *getComponent(int index) const;
                virtual void addComponent(PathComponent *component);

                virtual void render(video::Renderer *renderer) const;
        };
    }
}
#endif
