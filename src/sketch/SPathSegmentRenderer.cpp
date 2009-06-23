#include "SPathSegmentRenderer.h"
#include "PathRenderer.h"
#include "PathSegment.h"
#include "CPathSegmentRenderer.h"

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
        SPathSegmentRenderer::SPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        SPathSegmentRenderer::~SPathSegmentRenderer()
        {
        }

        void SPathSegmentRenderer::vectors(video::Renderer *renderer,
                PathSegment *segment, bool fill)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            char lastCommand = 
                    pathRenderer->getLastSegment()->getLowerCaseCommand();

            Vector2D control;
            if(lastCommand == 'c' || lastCommand == 's') {
                control = pathRenderer->getLastControlPoint();
                control = pathRenderer->getCurrentPoint().reflect(control);
            } else {
                control = pathRenderer->getCurrentPoint();
            }

            if(segment->isRelativeCommand())
                control -= pathRenderer->getCurrentPoint();

            char command = segment->isRelativeCommand() ? 'c' : 'C';
            vector<float> arguments;

            for(int i = 0; i + 3 < segment->getNumberOfArguments(); i += 4) {
                arguments.push_back(control.getX());
                arguments.push_back(control.getY());
                arguments.push_back(segment->getArgument(i));
                arguments.push_back(segment->getArgument(i + 1));
                arguments.push_back(segment->getArgument(i + 2));
                arguments.push_back(segment->getArgument(i + 3));

                /* New control point now. */
                control = Vector2D(segment->getArgument(i + 2),
                        segment->getArgument(i + 3)).reflect(
                        Vector2D(segment->getArgument(i),
                        segment->getArgument(i + 1)));
            }

            PathSegment *cPathSegment = new PathSegment(command, arguments);
            PathSegmentRenderer *cPathRenderer =
                    new CPathSegmentRenderer(pathRenderer);
            cPathRenderer->vectors(renderer, cPathSegment, fill);
            delete cPathSegment;
            delete cPathRenderer;
        }
    }
}