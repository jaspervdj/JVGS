#include "EffectManager.h"

using namespace jvgs::core;
using namespace std;

namespace jvgs
{
    namespace effect
    {
        EffectManager::EffectManager()
        {
        }

        EffectManager::~EffectManager()
        {
        }

        EffectManager *EffectManager::getInstance()
        {
            static EffectManager instance;
            return &instance;
        }

        void EffectManager::addEffect(View *effect)
        {
            effects.push_back(effect);
        }

        void EffectManager::clear()
        {
            for(vector<View*>::iterator iterator = effects.begin();
                    iterator != effects.end(); iterator++)
                delete *iterator;
            effects.clear();
        }

        void EffectManager::update(float ms)
        {
            vector<View*> remaining;

            for(vector<View*>::iterator iterator = effects.begin();
                    iterator != effects.end(); iterator++) {
                (*iterator)->update(ms);
                if(!(*iterator)->isGarbage())
                    remaining.push_back(*iterator);
                else
                    delete *iterator;
            }

            effects = remaining;
        }

        void EffectManager::render()
        {
            for(vector<View*>::iterator iterator = effects.begin();
                    iterator != effects.end(); iterator++)
                (*iterator)->render();
        }
    }
}
