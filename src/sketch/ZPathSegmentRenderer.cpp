#include "ZPathSegmentRenderer.h"
#include "PathRenderer.h"

#include "../video/Renderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        ZPathSegmentRenderer::ZPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        ZPathSegmentRenderer::~ZPathSegmentRenderer()
        {
        }

        void ZPathSegmentRenderer::vectors(Renderer *renderer,
                PathSegment *segment, bool fill)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            renderer->vector(pathRenderer->getStartingPoint());
            renderer->end();
        }
    }
}
