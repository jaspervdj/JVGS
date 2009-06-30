#ifndef JVGS_SKETCH_PATHCOMPONENT_H
#define JVGS_SKETCH_PATHCOMPONENT_H

#include <vector>
#include "../math/PathSegment.h"
#include "../video/Renderer.h"

namespace jvgs
{
    namespace sketch
    {
        class Path;

        class PathComponent
        {
            private:
                Path *path;
                std::vector<math::PathSegment*> segments;

            public:
                PathComponent(Path *path);
                virtual ~PathComponent();

                virtual Path *getPath() const;

                virtual int getNumberOfSegments() const;
                virtual math::PathSegment *getSegment(int index) const;
                virtual void addSegment(math::PathSegment *segment);

                virtual void render(video::Renderer *renderer) const;
        };
    }
}
#endif
