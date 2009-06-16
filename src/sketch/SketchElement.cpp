#include "SketchElement.h"
#include "StyleMap.h"

using namespace jvgs::video;
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        SketchElement::SketchElement(SketchElement *parent)
        {
            this->parent = parent;
            styleMap = new StyleMap(parent ? parent->getStyleMap() : 0 );


            matrix = AffineTransformationMatrix();
        }

        SketchElement::~SketchElement()
        {
            delete styleMap;
        }

        SketchElement *SketchElement::getParent() const
        {
            return parent;
        }

        StyleMap *SketchElement::getStyleMap() const
        {
            return styleMap;
        }

        void SketchElement::setMatrix(const AffineTransformationMatrix &matrix)
        {
            this->matrix = matrix;
        }

        const AffineTransformationMatrix &SketchElement::getMatrix() const
        {
            return matrix;
        }
    }
}
