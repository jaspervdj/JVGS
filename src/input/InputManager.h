#ifndef JVGS_INPUT_INPUTMANAGER_H
#define JVGS_INPUT_INPUTMANAGER_H

#include <vector>
#include <SDL.h>
#include "Key.h"

namespace jvgs
{
    namespace input
    {
        class KeyListener;

        /** Singleton to manage input.
         */
        class InputManager
        {
            private:
                /** Key state. */
                Uint8 *keyState;

                /** Received a quit event. */
                bool quitEvent;

                /** Array of ticked keys. */
                bool *tickedKeys;

            protected:
                /** Constructor.
                 */
                InputManager();

                /** Destructor.
                 */
                virtual ~InputManager();

            public:
                /** Get the singleton instance.
                 *  @return The InputManager instance.
                 */
                static InputManager *getInstance();

                /** This function ckecks if a certain key is down.
                 *  @param key Key to check.
                 *  @return If the key is down.
                 */
                bool isKeyDown(const Key &key) const;

                /** This function checks if a certain key was ticked since the
                 *  last update.
                 *  @param key Key to check.
                 *  @return If the key was ticked.
                 */
                bool isKeyTicked(const Key &key) const;

                /** Update the InputManager for a certain amount of time.
                 *  @param ms Time to update for.
                 */
                void update(float ms);

                /** Check if the InputManager received a quit event.
                 *  @return If the InputManager received a quit event.
                 */
                bool hasQuitEvent() const;

                /** Send a simulated quit event.
                 */
                void sendQuitEvent();
        };
    }
}

#endif
