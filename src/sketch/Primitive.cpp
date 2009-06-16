#include "Primitive.h"
#include "StyleMap.h"

using namespace jvgs::video;
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        Primitive::Primitive(Primitive *parent)
        {
            this->parent = parent;
            styleMap = new StyleMap(parent ? parent->getStyleMap() : 0 );


            matrix = AffineTransformationMatrix();
        }

        Primitive::~Primitive()
        {
            delete styleMap;
        }

        Primitive *Primitive::getParent() const
        {
            return parent;
        }

        StyleMap *Primitive::getStyleMap() const
        {
            return styleMap;
        }

        void Primitive::setMatrix(const AffineTransformationMatrix &matrix)
        {
            this->matrix = matrix;
        }

        const AffineTransformationMatrix &Primitive::getMatrix() const
        {
            return matrix;
        }
    }
}
