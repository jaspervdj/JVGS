#include "FPSLogger.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

namespace jvgs
{
    namespace video
    {
        FPSLogger::FPSLogger()
        {
            time = 0;
            frames = 0;
        }

        FPSLogger::~FPSLogger()
        {
        }

        void FPSLogger::update(float ms)
        {
            time += (long) ms;
            if(time > 1000) {
                float fps = (float) frames * 1000.0f / (float) time;
                LogManager::getInstance()->message("FPS: %f", fps);
                time = 0;
                frames = 0;
            }
        }

        void FPSLogger::render()
        {
            frames++;
        }
    }
}
