#include "LifeEffect.h"

namespace jvgs
{
    namespace effect
    {
        LifeEffect::LifeEffect(float life)
        {
            initialLife = life;
            this->life = life;
        }

        LifeEffect::~LifeEffect()
        {
        }

        void LifeEffect::update(float ms)
        {
            if(life > 0.0f) {
                if(life - ms <= 0.0f)
                    setGarbage();
                else
                    life -= ms;
            }
        }

        float LifeEffect::getInitialLife() const
        {
            return initialLife;
        }

        float LifeEffect::getLife() const
        {
            return life;
        }

        float LifeEffect::getLifeFraction() const
        {
            return life / initialLife;
        }

        bool LifeEffect::isImmortal() const
        {
            return life <= 0.0f;
        }
    }
}
