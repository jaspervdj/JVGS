#ifndef JVGS_SKETCH_PATHSEGMENTRENDERER_H
#define JVGS_SKETCH_PATHSEGMENTRENDERER_H

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

                virtual void render(PathSegment *segment) = 0;
        };
    }
}

#endif
