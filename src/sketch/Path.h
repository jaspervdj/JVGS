#ifndef JVGS_SKETCH_PATH_H
#define JVGS_SKETCH_PATH_H

#include "Primitive.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class PathSegment;

        class Path: public Primitive
        {
            private:
                std::vector<PathSegment*> segments;

            public:
                Path(SketchElement *parent);
                virtual ~Path();

                virtual int getNumberOfSegments() const;
                virtual PathSegment *getSegment(int index) const;
                virtual void addSegment(PathSegment *segment);

                virtual SketchElementRenderer *createSketchElementRenderer();
        };
    }
}
#endif
