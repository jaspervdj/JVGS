#include "LPathSegmentRenderer.h"
#include "PathSegment.h"
#include "PathRenderer.h"

namespace jvgs
{
    namespace sketch
    {
        LPathSegmentRenderer::LPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        LPathSegmentRenderer::~LPathSegmentRenderer()
        {
        }

        void LPathSegmentRenderer::render(PathSegment *segment)
        {
            PathRenderer *pathRenderer = getPathRenderer();

            pathRenderer->setFirstSegment(false);
        }
    }
}
