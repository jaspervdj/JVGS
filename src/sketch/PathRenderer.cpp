#include "PathRenderer.h"
#include "Path.h"
#include "PathSegment.h"
#include "PathSegmentRenderer.h"
#include "LPathSegmentRenderer.h"

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
        }

        PathRenderer::~PathRenderer()
        {
            for(map<char, PathSegmentRenderer*>::iterator iterator =
                    segmentRenderers.begin();
                    iterator != segmentRenderers.end(); iterator++) {
                delete iterator->second;
            }
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
            renderer->begin(Renderer::POLYGON);
            vectors(renderer);
            renderer->end();
        }

        void PathRenderer::stroke(Renderer *renderer)
        {
            renderer->begin(Renderer::LINES);
            vectors(renderer);
            renderer->end();
        }

        void PathRenderer::vectors(Renderer *renderer)
        {
            for(int i = 0; i < path->getNumberOfSegments(); i++) {
                PathSegment *segment = path->getSegment(i);

                map<char, PathSegmentRenderer*>::iterator iterator =
                        segmentRenderers.find(segment->getLowerCaseCommand());
                if(iterator != segmentRenderers.end()) {
                    PathSegmentRenderer *segmentRenderer = iterator->second;
                    segmentRenderer->render(segment);
                }
            }
        }
    }
}
