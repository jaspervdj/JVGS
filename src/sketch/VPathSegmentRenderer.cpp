#include "VPathSegmentRenderer.h"
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
        VPathSegmentRenderer::VPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        VPathSegmentRenderer::~VPathSegmentRenderer()
        {
        }

        void VPathSegmentRenderer::vectors(video::Renderer *renderer,
                PathSegment *segment)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            Vector2D current = pathRenderer->getCurrentPoint();

            char command = segment->isRelativeCommand() ? 'l' : 'L';
            vector<float> arguments;

            for(int i = 0; i < segment->getNumberOfArguments(); i++) {
                arguments.push_back(segment->isRelativeCommand() ?
                        0.0f : current.getX());
                arguments.push_back(segment->getArgument(0));
            }

            PathSegment *lPathSegment = new PathSegment(command, arguments);
            PathSegmentRenderer *lPathRenderer =
                    new LPathSegmentRenderer(pathRenderer);
            lPathRenderer->vectors(renderer, lPathSegment);
            delete lPathSegment;
            delete lPathRenderer;
        }
    }
}
