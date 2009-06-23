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
                PathSegment *segment)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            renderer->vector(pathRenderer->getStartingPoint());
            pathRenderer->setCurrentPoint(pathRenderer->getStartingPoint());
            renderer->end();
        }
    }
}
