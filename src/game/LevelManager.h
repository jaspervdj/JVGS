#ifndef JVGS_GAME_LEVELMANAGER_H
#define JVGS_GAME_LEVELMANAGER_H

#include <string>

namespace jvgs
{
    namespace game
    {
        class Level;

        /** Singleton class to manage levels.
         */
        class LevelManager
        {
            private:
                /** Current level. */
                Level *level;

                /** Is there something in the queue? */
                bool queue;

                /** Queue. */
                std::string queueFileName;

                /** Time factor. */
                float timeFactor;

            protected:
                /** Constructor.
                 */
                LevelManager();

                /** Destructor.
                 */
                virtual ~LevelManager();

            public:
                /** Get the LevelManager instance.
                 *  @return The LevelManager instance.
                 */
                static LevelManager *getInstance();
                
                /** Get the current level.
                 *  @return The current level.
                 */
                virtual Level *getLevel() const;

                /** Never returns.
                 */
                virtual void run();

                /** Queue a level. This means the next update, the previous
                 *  level will be removed ans this level will be set.
                 *  @param fileName File name of the level to run.
                 */
                virtual void queueLevel(const std::string &fileName);

                /** Get the time factor.
                 *  @return The current time factor.
                 */
                virtual float getTimeFactor() const;

                /** Set the time factor.
                 *  @param timeFactor The new time factor.
                 */
                virtual void setTimeFactor(float timeFactor);
        };
    }
}

#endif
