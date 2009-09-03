#include "LevelManager.h"
#include "Level.h"

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
        }

        LevelManager::~LevelManager()
        {
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

            FPSLogger fps;

            long lastUpdate = timeManager->getTicks();
            while(!inputManager->hasQuitEvent()) {

                long ticks = timeManager->getTicks();
                float ms = (float)(ticks - lastUpdate);
                lastUpdate = ticks;

                inputManager->update(ms);

                if(level && ms > 0.0f)
                    level->update(ms);

                effectManager->update(ms);
                fps.update(ms);

                videoManager->clear();
                videoManager->identity();

                if(level)
                    level->render();

                effectManager->render();
                fps.render();

                videoManager->flip();

                if(queue) {
                    /* Remove old level. */
                    if(level)
                        delete level;

                    effectManager->clear();

                    /* Load new level. */
                    level = new Level(queueFileName);
                    queue = false;
                }
            }
        }

        void LevelManager::queueLevel(const string &fileName)
        {
            queue = true;
            queueFileName = fileName;
        }
    }
}
