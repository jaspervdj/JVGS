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

                /** If the audio is teh epic fail. */
                bool failed;

            protected:
                /** Constructor.
                 */
                AudioManager();

                /** Destructor.
                 */
                virtual ~AudioManager();

                /** Helper function for getting sounds.
                 *  @param fileName Sound to get.
                 *  @return The requested sound.
                 */
                virtual Mix_Chunk *getSound(const std::string &fileName);

            public:
                /** Get the AudioManager instance.
                 *  @return The AudioManager instance.
                 */
                static AudioManager *getInstance();

                /** Load a sound. Can be used to load a sound before playing it,
                 *  so there is no in-game delay.
                 *  @param fileName File name of the sound.
                 */
                void loadSound(const std::string &fileName);

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
