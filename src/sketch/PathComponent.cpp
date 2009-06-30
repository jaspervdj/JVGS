#include "PathComponent.h"
#include "Path.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace jvgs::video;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        PathComponent::PathComponent(Path *path)
        {
            this->path = path;
        }

        PathComponent::~PathComponent()
        {
            for(vector<PathSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++)
                delete (*iterator);
        }

        Path *PathComponent::getPath() const
        {
            return path;
        }

        int PathComponent::getNumberOfSegments() const
        {
            return segments.size();
        }

        PathSegment *PathComponent::getSegment(int index) const
        {
            return segments[index];
        }

        void PathComponent::addSegment(PathSegment *segment)
        {
            segments.push_back(segment);
        }

        void PathComponent::render(Renderer *renderer) const
        {
        }
    }
}
