#include "CPathSegmentRenderer.h"
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
        CPathSegmentRenderer::CPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        CPathSegmentRenderer::~CPathSegmentRenderer()
        {
        }

        void CPathSegmentRenderer::vectors(video::Renderer *renderer,
                PathSegment *segment)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            Vector2D last = pathRenderer->getCurrentPoint();

            renderer->vector(last);
            for(int i = 0; i + 5 < segment->getNumberOfArguments(); i += 6) {
                Vector2D control1(segment->getArgument(i),
                                  segment->getArgument(i + 1));
                Vector2D control2(segment->getArgument(i + 2),
                                  segment->getArgument(i + 3));
                Vector2D destination(segment->getArgument(i + 4),
                                     segment->getArgument(i + 5));

                if(segment->isRelativeCommand()) {
                    control1 += pathRenderer->getCurrentPoint();
                    control2 += pathRenderer->getCurrentPoint();
                    destination += pathRenderer->getCurrentPoint();
                }

                float distance = 0.5f * (last.distance(control1) +
                        control1.distance(control2) +
                        control2.distance(destination));

                float increment = LINE_SEGMENT_SIZE / distance;
                for(float t = 0.0f; t <= 1.0f; t += increment) {
                    Vector2D v1 = last * (1.0f - t) + control1 * t;
                    Vector2D v2 = control1 * (1.0f - t) + control2 * t;
                    Vector2D v3 = control2 * (1.0f - t) + destination * t;
                    Vector2D u1 = v1 * (1.0f - t) + v2 * t;
                    Vector2D u2 = v2 * (1.0f - t) + v3 * t;
                    renderer->vector(u1 * (1.0f - t) + u2 * t);
                }

                last = destination;
                pathRenderer->setLastControlPoint(control2);
            }

            pathRenderer->setCurrentPoint(last);
        }
    }
}
