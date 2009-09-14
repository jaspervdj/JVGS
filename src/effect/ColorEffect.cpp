#include "ColorEffect.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace effect
    {
        ColorEffect::ColorEffect(const Color &color, const Color &clearColor,
                float life) : LifeEffect(life)
        {
            VideoManager *videoManager = VideoManager::getInstance();
            originalColor = videoManager->getColor();
            originalClearColor = videoManager->getClearColor();

            videoManager->setColor(color);
            videoManager->setClearColor(clearColor);
        }

        ColorEffect::~ColorEffect()
        {
            VideoManager *videoManager = VideoManager::getInstance();
            videoManager->setColor(originalColor);
            videoManager->setClearColor(originalClearColor);
        }

        void ColorEffect::render()
        {
        }
    }
}
