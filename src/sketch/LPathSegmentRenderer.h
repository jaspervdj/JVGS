#ifndef JVGS_SKETCH_LPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_LPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class LPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                LPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~LPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment);
        };
    }
}

#endif
