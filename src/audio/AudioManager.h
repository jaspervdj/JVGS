#ifndef JVGS_AUDIO_AUDIOMANAGER_H
#define JVGS_AUDIO_AUDIOMANAGER_H

#include <map>
#include <string>
#include <SDL_mixer.h>

namespace jvgs
{
    namespace audio
    {
        /** Class to manage audio.
         */
        class AudioManager
        {
            private:
                /** Cached sounds. */
                std::map<std::string, Mix_Chunk*> sounds;

                /** Playing music. */
                Mix_Music *music;

            protected:
                /** Constructor.
                 */
                AudioManager();

                /** Destructor.
                 */
                virtual ~AudioManager();

            public:
                /** Get the AudioManager instance.
                 *  @return The AudioManager instance.
                 */
                static AudioManager *getInstance();

                /** Play a sound.
                 *  @param fileName File name of the sound.
                 */
                void playSound(const std::string &fileName);

                /** Play background music (streaming).
                 *  @param fileName File name of the music.
                 */
                void playMusic(const std::string &fileName);
        };
    }
}

#endif
