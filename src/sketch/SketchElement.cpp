#include "SketchElement.h"
#include "../math/AffineTransformationMatrix.h"

#include <string>
using namespace std;

using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        SketchElement::SketchElement(SketchElement *parent)
        {
            this->parent = parent;
            matrix = AffineTransformationMatrix();
            id = "none";
        }

        SketchElement::~SketchElement()
        {
        }

        SketchElement *SketchElement::getParent() const
        {
            return parent;
        }

        void SketchElement::setMatrix(const AffineTransformationMatrix &matrix)
        {
            this->matrix = matrix;
        }

        const AffineTransformationMatrix &SketchElement::getMatrix() const
        {
            return matrix;
        }

        AffineTransformationMatrix SketchElement::getCompleteMatrix() const
        {
            AffineTransformationMatrix complete = matrix;
            SketchElement *element = getParent();
            while(element) {
                complete *= element->getMatrix();
                element = element->getParent();
            }

            return complete;
        }

        const string &SketchElement::getId() const
        {
            return id;
        }

        void SketchElement::setId(const string &id)
        {
            this->id = id;
        }
    }
}
