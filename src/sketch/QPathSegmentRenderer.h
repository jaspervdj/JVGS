#ifndef JVGS_SKETCH_QPATHSEGMENTRENDERER_H
#define JVGS_SKETCH_QPATHSEGMENTRENDERER_H

#include "PathSegmentRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        class QPathSegmentRenderer: public PathSegmentRenderer
        {
            private:
            public:
                QPathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~QPathSegmentRenderer();

                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment, bool fill);
        };
    }
}

#endif
