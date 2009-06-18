#ifndef JVGS_SKETCH_MPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_MPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class MPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                MPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~MPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment);
        };
    }
}

#endif
