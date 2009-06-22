#include "HPathSegmentRenderer.h"
#include "PathRenderer.h"
#include "PathSegment.h"
#include "LPathSegmentRenderer.h"

#include <iostream>
#include <vector>
using namespace std;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../video/Renderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        HPathSegmentRenderer::HPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        HPathSegmentRenderer::~HPathSegmentRenderer()
        {
        }

        void HPathSegmentRenderer::vectors(video::Renderer *renderer,
                PathSegment *segment, bool fill)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            Vector2D current = pathRenderer->getCurrentPoint();

            char command = segment->isRelativeCommand() ? 'l' : 'L';
            vector<float> arguments;

            arguments.push_back(segment->getArgument(0));
            arguments.push_back(segment->isRelativeCommand() ?
                    0.0f : current.getY());

            PathSegment *lPathSegment = new PathSegment(command, arguments);
            PathSegmentRenderer *lPathRenderer =
                    new LPathSegmentRenderer(pathRenderer);
            lPathRenderer->vectors(renderer, lPathSegment, fill);
            delete lPathSegment;
            delete lPathRenderer;
        }
    }
}
