#include "Renderer.h"
#include "VideoManager.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <cmath>
using namespace std;

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

        void Renderer::begin(RenderType type)
        {
            busy = true;
            rendering = type;
        }

        void Renderer::end()
        {
            busy = false;
        }

        bool Renderer::isBusy() const
        {
            return busy;
        }
    };
};
