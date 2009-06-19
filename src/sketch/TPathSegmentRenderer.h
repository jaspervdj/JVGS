#ifndef JVGS_SKETCH_TPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_TPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class TPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                TPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~TPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment, bool fill);
        };
    }
}

#endif
