#include "Primitive.h"

using namespace jvgs::video;
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        Primitive::Primitive()
        {
            stroke = false;
            strokeColor = Color(0.0f,0.0f,0.0f);
            fill = false;
            fillColor = Color(0.0f,0.0f,0.0f);
            matrix = AffineTransformationMatrix();
        }

        Primitive::~Primitive()
        {
        }

        void Primitive::setStroke(bool stroke)
        {
            this->stroke = stroke;
        }

        bool Primitive::hasStroke() const
        {
            return stroke;
        }

        void Primitive::setStrokeColor(const Color &color)
        {
            this->strokeColor = color;
        }

        Color Primitive::getStrokeColor() const
        {
            return strokeColor;
        }

        void Primitive::setFill(bool fill)
        {
            this->fill = fill;
        }

        bool Primitive::hasFill() const
        {
            return fill;
        }

        void Primitive::setFillColor(const Color &color)
        {
            this->fillColor = color;
        }

        Color Primitive::getFillColor() const
        {
            return fillColor;
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
