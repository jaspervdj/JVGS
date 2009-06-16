#include "Path.h"

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

        int Path::getNumberOfPoints()
        {
            return 42;
        }

        Vector2D Path::getPoint(int index)
        {
            return Vector2D();
        }

        SketchElementRenderer *Path::createSketchElementRenderer()
        {
            return 0;
        }
    }
}
