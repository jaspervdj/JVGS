#include "PathSegmentRenderer.h"
#include "PathRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        PathSegmentRenderer::PathSegmentRenderer(PathRenderer *pathRenderer)
        {
            this->pathRenderer = pathRenderer;
        }

        PathSegmentRenderer::~PathSegmentRenderer()
        {
        }
    }
}
