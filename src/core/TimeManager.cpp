#include "TimeManager.h"

#include <SDL.h>

namespace jvgs
{
    namespace core
    {
        TimeManager::TimeManager()
        {
        }

        TimeManager::~TimeManager()
        {
        }

        TimeManager *TimeManager::getInstance()
        {
            static TimeManager instance;
            return &instance;
        }

        long TimeManager::getTicks() const
        {
            return SDL_GetTicks();
        }
    }
}
