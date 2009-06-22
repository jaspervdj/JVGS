#ifndef JVGS_SKETCH_VPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_VPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class VPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                VPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~VPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment, bool fill);
        };
    }
}

#endif
