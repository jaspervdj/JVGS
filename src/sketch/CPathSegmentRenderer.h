#ifndef JVGS_SKETCH_CPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_CPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class CPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                CPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~CPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment, bool fill);
        };
    }
}

#endif
