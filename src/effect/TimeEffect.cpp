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
            this->timeFactor = timeFactor;
            LevelManager::getInstance()->setTimeFactor(timeFactor);
        }

        TimeEffect::~TimeEffect()
        {
            LevelManager::getInstance()->setTimeFactor(1.0f);
        }

        void TimeEffect::update(float ms)
        {
            LifeEffect::update(ms);

            if(isImmortal()) {
                LevelManager::getInstance()->setTimeFactor(timeFactor);
            } else {
                float fraction = getLifeFraction();
                float factor = (timeFactor - 1.0f) * fraction + 1.0f;
                LevelManager::getInstance()->setTimeFactor(factor);
            }
        }

        void TimeEffect::render()
        {
        }
    }
}
