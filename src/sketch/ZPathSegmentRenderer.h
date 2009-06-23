#ifndef JVGS_SKETCH_ZPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_ZPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class ZPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                ZPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~ZPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment);
        };
    }
}

#endif
