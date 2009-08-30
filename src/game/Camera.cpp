#include "Camera.h"

namespace jvgs
{
    namespace game
    {
        Camera::Camera(Level *level)
        {
            this->level = level;
        }

        Camera::~Camera()
        {
        }

        Level *Camera::getLevel() const
        {
            return level;
        }
    }
}
