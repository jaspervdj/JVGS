#include "KeyListener.h"
#include "InputManager.h"
#include <SDL.h>

namespace jvgs
{
    namespace input
    {
        KeyListener::KeyListener()
        {
        }

        KeyListener::~KeyListener()
        {
        }

        bool KeyListener::isKeyDown(const Key &key) const
        {
            return InputManager::getInstance()->isKeyDown(key);
        }
    }
}
