#include "Path.h"
#include "PathSegment.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        Path::Path(SketchElement *parent): Primitive(parent)
        {
        }

        Path::~Path()
        {
        }

        int Path::getNumberOfSegments() const
        {
            return segments.size();
        }

        PathSegment *Path::getSegment(int index) const
        {
            return segments[index];
        }

        void Path::addSegment(PathSegment *segment)
        {
            segments.push_back(segment);
        }

        SketchElementRenderer *Path::createSketchElementRenderer()
        {
            return 0;
        }
    }
}
