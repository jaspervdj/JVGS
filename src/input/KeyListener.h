#ifndef JVGS_INPUT_KEYLISTENER_H
#define JVGS_INPUT_KEYLISTENER_H

#include "Key.h"

namespace jvgs
{
    namespace input
    {
        /** A class that receives key events from the InputManager.
         */
        class KeyListener
        {
            private:
            public:
                /** Constructor.
                 */
                KeyListener();

                /** Destructor.
                 */
                virtual ~KeyListener();

                /** @copydoc InputManager::isKeyDown()
                 */
                virtual bool isKeyDown(const Key &key) const;

                /** This function is called when a key is pressed, aka the key
                 *  state changes from being released to being pressed.
                 *  @param key The key that was pressed.
                 */
                virtual void keyPressed(const Key &key) = 0;
        };
    }
}

#endif
