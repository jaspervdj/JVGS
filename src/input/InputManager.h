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
                /** Registered keyListeners. */
                std::vector<KeyListener*> keyListeners;

                /** Key state. */
                Uint8 *keyState;

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
                 *  @copydoc InputManager::isKeyDown()
                 */
                bool isKeyDown(const Key &key) const;

                /** Update the InputManager for a certain amount of time.
                 *  @param ms Time to update for.
                 */
                void update(float ms);

                /** Register a new KeyListener. It will not be deleted.
                 *  @param keyListener KeyListener to register.
                 */
                void addKeyListener(KeyListener *keyListener);

                /** Remove a KeyListener. It will not receive events anumore.
                 *  @param keyListener KeyListener to remove.
                 */
                void removeKeyListener(KeyListener *keyListener);
        };
    }
}

#endif
