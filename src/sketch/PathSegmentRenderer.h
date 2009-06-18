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

            public:
                PathSegmentRenderer(PathRenderer *pathRenderer);
                virtual ~PathSegmentRenderer();

                virtual PathRenderer *getPathRenderer() const;
                virtual void vectors(video::Renderer *renderer,
                        PathSegment *segment) = 0;
        };
    }
}

#endif
