#include "FadeEffect.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace effect
    {
        FadeEffect::FadeEffect(float life): LifeEffect(life)
        {
            color = VideoManager::getInstance()->getColor();
        }

        FadeEffect::~FadeEffect()
        {
            VideoManager::getInstance()->setColor(color);
        }

        void FadeEffect::render()
        {
            float t0 = getLifeFraction();
            float t1 = 1.0f - t0;
            Color clear = VideoManager::getInstance()->getClearColor();
            Color mix(color.getRed() * t0 + clear.getRed() * t1,
                    color.getGreen() * t0 + clear.getGreen() * t1,
                    color.getBlue() * t0 + clear.getBlue() * t1,
                    color.getAlpha() * t0 + clear.getAlpha() * t1);
            VideoManager::getInstance()->setColor(mix);
        }
    }
}
