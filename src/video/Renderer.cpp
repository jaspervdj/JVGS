#include "Renderer.h"

#include "VideoManager.h"

#include "../math/MathManager.h"
using namespace jvgs::math;

#include <iostream>
#include <cmath>

namespace jvgs
{
    namespace video
    {
        Renderer::Renderer()
        {
        }

        Renderer::~Renderer()
        {
        }

        void Renderer::begin(GLuint type) const
        {
            glBegin(type);
        }

        void Renderer::end() const
        {
            glEnd();
        }

        void Renderer::vector(const Vector2D &vector) const
        {
            glVertex2f(vector.getX(), vector.getY());
        }
    };
};
