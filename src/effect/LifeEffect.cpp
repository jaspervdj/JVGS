#include "LifeEffect.h"

namespace jvgs
{
    namespace effect
    {
        LifeEffect::LifeEffect(float life)
        {
            this->life = life;
        }

        LifeEffect::~LifeEffect()
        {
        }

        void LifeEffect::update(float ms)
        {
            life -= ms;
            if(life <= 0.0f)
                setGarbage();
        }
    }
}
