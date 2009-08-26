#include "InvertEffect.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace effect
    {
        InvertEffect::InvertEffect(float life): LifeEffect(life)
        {
            VideoManager::getInstance()->invert();
        }

        InvertEffect::~InvertEffect()
        {
            VideoManager::getInstance()->invert();
        }

        void InvertEffect::update(float ms)
        {
            LifeEffect::update(ms);
        }

        void InvertEffect::render()
        {
        }
    }
}
