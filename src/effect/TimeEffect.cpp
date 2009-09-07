#include "TimeEffect.h"

#include "../game/LevelManager.h"
using namespace jvgs::game;

namespace jvgs
{
    namespace effect
    {
        TimeEffect::TimeEffect(float timeFactor, float life)
                : LifeEffect(life)
        {
            LevelManager::getInstance()->setTimeFactor(timeFactor);
        }

        TimeEffect::~TimeEffect()
        {
            LevelManager::getInstance()->setTimeFactor(1.0f);
        }

        void TimeEffect::update(float ms)
        {
            LifeEffect::update(ms);
        }

        void TimeEffect::render()
        {
        }
    }
}
