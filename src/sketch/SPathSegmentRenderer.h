#ifndef JVGS_SKETCH_SPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_SPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class SPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                SPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~SPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment, bool fill);
        };
    }
}

#endif
