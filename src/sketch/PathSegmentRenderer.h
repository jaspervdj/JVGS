#ifndef JVGS_SKETCH_PATHSEGMENTRENDERER_H
#define JVGS_SKETCH_PATHSEGMENTRENDERER_H

#include "../video/Renderer.h"

namespace jvgs
{
    namespace sketch
    {
        class PathRenderer;
        class PathSegment;

        class PathSegmentRenderer
        {
            private:
                PathRenderer *pathRenderer;

            protected:
                static const float LINE_SEGMENT_SIZE = 1.0f;

            public:
                PathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~PathSegmentRenderer();

                virtual PathRenderer *getPathRenderer() const;
                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment, bool fill) = 0;
        };
    }
}

#endif
