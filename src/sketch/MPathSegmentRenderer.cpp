#include "MPathSegmentRenderer.h"
#include "PathSegment.h"
#include "PathRenderer.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        MPathSegmentRenderer::MPathSegmentRenderer(PathRenderer *pathRenderer):
            PathSegmentRenderer(pathRenderer)
        {
        }

        MPathSegmentRenderer::~MPathSegmentRenderer()
        {
        }

        void MPathSegmentRenderer::vectors(Renderer *renderer,
                PathSegment *segment)
        {
            PathRenderer *pathRenderer = getPathRenderer();

            Vector2D current = pathRenderer->getCurrentPoint();
            Vector2D translation(segment->getArgument(0),
                                 segment->getArgument(1));
            if(segment->isRelativeCommand())
                pathRenderer->setCurrentPoint(current + translation);
            else
                pathRenderer->setCurrentPoint(translation);
        }
    }
}
