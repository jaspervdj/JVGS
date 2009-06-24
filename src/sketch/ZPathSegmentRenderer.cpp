#include "ZPathSegmentRenderer.h"
#include "PathSegment.h"
#include "PathRenderer.h"
#include "LPathSegmentRenderer.h"

#include "../video/Renderer.h"
using namespace jvgs::video;

using namespace std;

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

            vector<float> arguments;
            arguments.push_back(pathRenderer->getStartingPoint().getX());
            arguments.push_back(pathRenderer->getStartingPoint().getY());

            PathSegment *lineSegment = new PathSegment('L', arguments);
            LPathSegmentRenderer *lineRenderer =
                    new LPathSegmentRenderer(pathRenderer);

            renderer->vector(pathRenderer->getStartingPoint());
            lineRenderer->vectors(renderer, lineSegment);
            delete lineSegment;
            delete lineRenderer;
            renderer->end();
        }
    }
}
