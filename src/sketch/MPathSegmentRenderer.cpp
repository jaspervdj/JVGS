#include "MPathSegmentRenderer.h"
#include "PathSegment.h"
#include "PathRenderer.h"
#include "LPathSegmentRenderer.h"

#include <vector>
using namespace std;

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
                PathSegment *segment, bool fill)
        {
            PathRenderer *pathRenderer = getPathRenderer();

            /* We can start a new line, so finish up the previous one. */
            if(renderer->isBusy())
                renderer->end();

            Vector2D translation(segment->getArgument(0),
                                 segment->getArgument(1));

            if(segment->isRelativeCommand())
                translation += pathRenderer->getCurrentPoint();

            pathRenderer->setCurrentPoint(translation);
            pathRenderer->setStartingPoint(translation);

            /* Start the new line. */
            if(fill)
                renderer->begin(Renderer::POLYGON);
            else
                renderer->begin(Renderer::LINE_STRIP);

            /* If a moveto is followed by multiple pairs of coordinates, the
             * subsequent pairs are treated as implicit lineto commands. (from
             * the SVG specification - heck, what sick mind invented this kind
             * of stuff? */
            if(segment->getNumberOfArguments() > 2) {

                /* Create a line segment. */
                char command = segment->isRelativeCommand() ? 'l' : 'L';
                vector<float> arguments;
                for(int i = 2; i < segment->getNumberOfArguments(); i++)
                    arguments.push_back(segment->getArgument(i));
                PathSegment *implicitLine = new PathSegment(command, arguments);

                /* Render it. */
                LPathSegmentRenderer *implicitLineRenderer =
                        new LPathSegmentRenderer(pathRenderer);
                implicitLineRenderer->vectors(renderer, implicitLine, fill);

                /* Clean up. */
                delete implicitLineRenderer;
                delete implicitLine;
            }
        }
    }
}
