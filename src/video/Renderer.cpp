#include "Renderer.h"

#include "VideoManager.h"

#include "../math/MathManager.h"
using namespace jvgs::math;

#include <cmath>

namespace jvgs
{
    namespace video
    {
        Renderer::Renderer()
        {
            busy = false;
        }

        Renderer::~Renderer()
        {
        }

        void Renderer::begin(Type type)
        {
            glBegin(type);
            busy = true;
        }

        void Renderer::end()
        {
            glEnd();
            busy = false;
        }

        bool Renderer::isBusy() const
        {
            return busy;
        }

        void Renderer::vector(const Vector2D &vector) const
        {
            glVertex2f(vector.getX(), vector.getY());
        }
    };
};
