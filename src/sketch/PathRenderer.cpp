#include "PathRenderer.h"
#include "Path.h"
#include "PathSegment.h"
#include "PathSegmentRenderer.h"
#include "LPathSegmentRenderer.h"
#include "MPathSegmentRenderer.h"
#include "ZPathSegmentRenderer.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace jvgs::video;
using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        PathRenderer::PathRenderer(Path *path): PrimitiveRenderer(path)
        {
            this->path = path;

            segmentRenderers['l'] = new LPathSegmentRenderer(this);
            segmentRenderers['m'] = new MPathSegmentRenderer(this);
            segmentRenderers['z'] = new ZPathSegmentRenderer(this);
        }

        PathRenderer::~PathRenderer()
        {
            for(map<char, PathSegmentRenderer*>::iterator iterator =
                    segmentRenderers.begin();
                    iterator != segmentRenderers.end(); iterator++) {
                delete iterator->second;
            }
        }

        bool PathRenderer::isFirstSegment() const
        {
            return firstSegment;
        }

        void PathRenderer::setFirstSegment(bool firstSegment)
        {
            this->firstSegment = firstSegment;
        }

        const Vector2D &PathRenderer::getStartingPoint() const
        {
            return startingPoint;
        }

        void PathRenderer::setStartingPoint(const Vector2D &startingPoint)
        {
            this->startingPoint = startingPoint;
        }

        const Vector2D &PathRenderer::getCurrentPoint() const
        {
            return currentPoint;
        }

        void PathRenderer::setCurrentPoint(const Vector2D &currentPoint)
        {
            this->currentPoint = currentPoint;
        }

        void PathRenderer::fill(Renderer *renderer)
        {
            vectors(renderer, true);
        }

        void PathRenderer::stroke(Renderer *renderer)
        {
            vectors(renderer, false);
        }

        void PathRenderer::vectors(Renderer *renderer, bool fill)
        {
            for(int i = 0; i < path->getNumberOfSegments(); i++) {

                PathSegment *segment = path->getSegment(i);

                map<char, PathSegmentRenderer*>::iterator iterator =
                        segmentRenderers.find(segment->getLowerCaseCommand());

                if(iterator != segmentRenderers.end()) {
                    PathSegmentRenderer *segmentRenderer = iterator->second;
                    segmentRenderer->vectors(renderer, segment, fill);
                } else {
                    LogManager::getInstance()->warning(
                            "%c command for paths is not (yet) implemented.",
                            segment->getLowerCaseCommand());
                }
            }

            /* Stop the renderer if left unclosed. */
            if(renderer->isBusy())
                renderer->end();
        }
    }
}
