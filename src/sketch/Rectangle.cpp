#include "Rectangle.h"
#include "RectangleRenderer.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        Rectangle::Rectangle(SketchElement *parent): Primitive(parent)
        {
            position = Vector2D();
            size = Vector2D();
        }

        Rectangle::~Rectangle()
        {
        }

        void Rectangle::setPosition(const Vector2D &position)
        {
            this->position = position;
        }

        const Vector2D &Rectangle::getPosition() const
        {
            return position;
        }

        void Rectangle::setSize(const Vector2D &size)
        {
            this->size = size;
        }

        const Vector2D &Rectangle::getSize() const
        {
            return size;
        }

        SketchElementRenderer *Rectangle::createSketchElementRenderer()
        {
            return new RectangleRenderer(this);
        }
    }
}
