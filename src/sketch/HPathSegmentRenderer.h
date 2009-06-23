#ifndef JVGS_SKETCH_HPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_HPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class HPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                HPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~HPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment);
        };
    }
}

#endif
