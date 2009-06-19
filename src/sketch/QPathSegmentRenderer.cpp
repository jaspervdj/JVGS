#include "QPathSegmentRenderer.h"
#include "PathRenderer.h"
#include "PathSegment.h"

#include <iostream>
using namespace std;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../video/Renderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        QPathSegmentRenderer::QPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        QPathSegmentRenderer::~QPathSegmentRenderer()
        {
        }

        void QPathSegmentRenderer::vectors(video::Renderer *renderer,
                PathSegment *segment, bool fill)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            Vector2D last = pathRenderer->getCurrentPoint();

            renderer->vector(last);
            for(int i = 0; i + 3 < segment->getNumberOfArguments(); i += 4) {
                Vector2D control(segment->getArgument(i),
                                 segment->getArgument(i + 1));
                Vector2D destination(segment->getArgument(i + 2),
                                     segment->getArgument(i + 3));

                if(segment->isRelativeCommand()) {
                    control += pathRenderer->getCurrentPoint();
                    destination += pathRenderer->getCurrentPoint();
                }

                float distance = 2.5f * (last.distance(control) +
                        control.distance(last));

                float increment = LINE_SEGMENT_SIZE / distance;
                for(float t = 0.0f; t <= 1.0f; t += increment) {
                    Vector2D v1 = last * (1.0f - t) + control * t;
                    Vector2D v2 = control * (1.0f - t) + destination * t;
                    renderer->vector(v1 * (1.0f - t) + v2 * t);
                }

                last = destination;
                pathRenderer->setLastControlPoint(control);
            }

            pathRenderer->setCurrentPoint(last);
        }
    }
}
