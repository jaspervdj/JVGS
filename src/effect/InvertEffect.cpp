#include "InvertEffect.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace effect
    {
        InvertEffect::InvertEffect(float life)
        {
            this->life = life;

            VideoManager::getInstance()->invert();
        }

        InvertEffect::~InvertEffect()
        {
            VideoManager::getInstance()->invert();
        }

        void InvertEffect::update(float ms)
        {
            life -= ms;
            if(life <= 0.0f)
                setGarbage();
        }

        void InvertEffect::render()
        {
        }
    }
}
