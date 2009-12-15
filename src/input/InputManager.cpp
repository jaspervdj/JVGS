#include "InputManager.h"

using namespace std;

namespace jvgs
{
    namespace input
    {
        InputManager::InputManager()
        {
            SDL_InitSubSystem(SDL_INIT_EVENTTHREAD);
            keyState = SDL_GetKeyState(0);
            quitEvent = false;
            tickedKeys = new bool[KEY_LAST];
        }

        InputManager::~InputManager()
        {
            SDL_QuitSubSystem(SDL_INIT_EVENTTHREAD);
            delete[] tickedKeys;
        }

        InputManager *InputManager::getInstance()
        {
            static InputManager instance;
            return &instance;
        }

        bool InputManager::isKeyDown(const Key &key) const
        {
            return (bool) keyState[key];
        }

        bool InputManager::isKeyTicked(const Key &key) const
        {
            return tickedKeys[key];
        }

        void InputManager::update(float ms)
        {
            for(int i = 0; i < KEY_LAST; i++)
                tickedKeys[i] = false;

            SDL_Event event;
            while(SDL_PollEvent(&event)) {
                switch(event.type) {
                    /* Key down - alert all listeners. */
                    case SDL_KEYDOWN:
                        if(event.key.keysym.sym == SDLK_ESCAPE) {
                            quitEvent = true;
                        } else {
                            tickedKeys[event.key.keysym.sym] = true;
                        }
                        break;
                    case SDL_QUIT:
                        quitEvent = true;
                        break;
                }
            }
        }

        bool InputManager::hasQuitEvent() const
        {
            return quitEvent;
        }

        void InputManager::sendQuitEvent()
        {
            quitEvent = true;
        }
    }
}
