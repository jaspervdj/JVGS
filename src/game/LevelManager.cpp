#include "LevelManager.h"
#include "Level.h"

#include "../sketch/SketchManager.h"
using namespace jvgs::sketch;

#include "../effect/EffectManager.h"
using namespace jvgs::effect;

#include "../video/VideoManager.h"
#include "../video/FPSLogger.h"
using namespace jvgs::video;

#include "../core/TimeManager.h"
using namespace jvgs::core;

#include "../input/InputManager.h"
using namespace jvgs::input;

using namespace std;

namespace jvgs
{
    namespace game
    {
        LevelManager::LevelManager()
        {
            level = 0;
            queue = false;
            timeFactor = 1.0f;
        }

        LevelManager::~LevelManager()
        {
            if(level)
                delete level;
        }

        LevelManager *LevelManager::getInstance()
        {
            static LevelManager instance;
            return &instance;
        }

        Level *LevelManager::getLevel() const
        {
            return level;
        }

        void LevelManager::run()
        {
            /* Behold, as I have been told
             * what follows below
             * is very important, you know! */
            InputManager *inputManager = InputManager::getInstance();
            TimeManager *timeManager = TimeManager::getInstance();
            VideoManager *videoManager = VideoManager::getInstance();
            EffectManager *effectManager = EffectManager::getInstance();
            SketchManager *sketchManager = SketchManager::getInstance();

            FPSLogger fps;

            long lastUpdate = timeManager->getTicks();
            while(!inputManager->hasQuitEvent()) {

                /* Calculate the ticks that have passed. */
                long ticks = timeManager->getTicks();
                float ms = (float)(ticks - lastUpdate);
                lastUpdate = ticks;

                /* Update the input state. */
                inputManager->update(ms);

                /* Update the level. */
                if(level && ms > 0.0f)
                    level->update(timeFactor * ms);

                /* Update other things. */
                effectManager->update(timeFactor * ms);
                fps.update(ms);

                /* Setup the videoManager for rendering. */
                videoManager->clear();
                videoManager->identity();

                /* Render the level first, this will also apply our camera
                 * transformation, which is good, since the effect manager
                 * wants the same transformation. */
                if(level)
                    level->render();
                effectManager->render();
                fps.render();

                /* Flip the video buffer. */
                videoManager->flip();

                /* Update level queue. */
                if(queue) {
                    /* Remove old level. */
                    if(level)
                        delete level;

                    effectManager->clear();
                    sketchManager->clear();

                    /* Load new level. */
                    level = new Level(queueFileName);
                    queue = false;
                    timeFactor = 1.0f;

                    /* Loading the level might have taken some time, so we skip
                     * some ticks. */
                    lastUpdate = timeManager->getTicks();
                }
            }
        }

        void LevelManager::queueLevel(const string &fileName)
        {
            queue = true;
            queueFileName = fileName;
        }

        float LevelManager::getTimeFactor() const
        {
            return timeFactor;
        }

        void LevelManager::setTimeFactor(float timeFactor)
        {
            this->timeFactor = timeFactor;
        }
    }
}
