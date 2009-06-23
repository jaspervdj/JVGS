#include "LPathSegmentRenderer.h"
#include "PathSegment.h"
#include "PathRenderer.h"

#include <iostream>
using namespace std;

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace jvgs::video;

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

        void LPathSegmentRenderer::vectors(Renderer *renderer,
                PathSegment *segment)
        {
            PathRenderer *pathRenderer = getPathRenderer();

            Vector2D current = pathRenderer->getCurrentPoint();
            renderer->vector(current);
            for(int i = 0; i + 1 < segment->getNumberOfArguments(); i += 2) {
                Vector2D destination(segment->getArgument(i),
                        segment->getArgument(i + 1));

                current = pathRenderer->getCurrentPoint();

                if(segment->isRelativeCommand())
                    destination += current;

                float distance = current.distance(destination);

                float increment = LINE_SEGMENT_SIZE / distance;
                for(float t = increment; t <= 1.0f; t += increment) {
                    renderer->vector(current * (1.0f - t) + destination * t);
                }

                /* Save the last vector. */
                pathRenderer->setCurrentPoint(destination);
            }
        }
    }
}
