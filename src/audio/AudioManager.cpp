#include "AudioManager.h"

#include "../core/LogManager.h"
#include "../core/DataManager.h"
using namespace jvgs::core;

#include <SDL.h>

using namespace std;

namespace jvgs
{
    namespace audio
    {
        AudioManager::AudioManager()
        {
            music = 0;
            if(SDL_InitSubSystem(SDL_INIT_AUDIO) ||
                    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
                    MIX_DEFAULT_FORMAT, 2, 1024))
                failed = true;
            else
                failed = false;
        }

        AudioManager::~AudioManager()
        {
            if(failed)
                return;

            for(map<string, Mix_Chunk*>::iterator iterator = sounds.begin();
                    iterator != sounds.end(); iterator++)
                Mix_FreeChunk(iterator->second);

            if(music)
                Mix_FreeMusic(music);

            Mix_CloseAudio();
            SDL_QuitSubSystem(SDL_INIT_AUDIO);
        }

        Mix_Chunk *AudioManager::getSound(const string &fileName)
        {
            Mix_Chunk *sound = 0;
            map<string, Mix_Chunk*>::iterator result = sounds.find(fileName);
            if(result != sounds.end()) {
                sound = result->second;
            } else {
                string expanded = DataManager::getInstance()->expand(fileName);
                sound = Mix_LoadWAV(expanded.c_str());
                sounds[fileName] = sound;
            }

            if(!sound)
                LogManager::getInstance()->warning(
                        "Could not open sound %s.", fileName.c_str());

            return sound;
        }

        AudioManager *AudioManager::getInstance()
        {
            static AudioManager instance;
            return &instance;
        }

        void AudioManager::loadSound(const string &fileName)
        {
            if(failed)
                return;

            getSound(fileName);
        }

        void AudioManager::playSound(const string &fileName)
        {
            if(failed)
                return;

            Mix_Chunk *sound = getSound(fileName);
            Mix_PlayChannel(-1, sound, 0);
        }

        void AudioManager::playMusic(const string &fileName)
        {
            if(failed)
                return;

            if(music)
                Mix_FreeMusic(music);

            string expanded = DataManager::getInstance()->expand(fileName);
            music = Mix_LoadMUS(expanded.c_str());
            if(music)
                Mix_PlayMusic(music, -1);
            else
                LogManager::getInstance()->warning(
                        "Could not open music %s.", fileName.c_str());
        }
    }
}
