#include "InputManager.h"
#include "KeyListener.h"

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
        }

        InputManager::~InputManager()
        {
            SDL_QuitSubSystem(SDL_INIT_EVENTTHREAD);
        }

        InputManager *InputManager::getInstance()
        {
            static InputManager instance;
            return &instance;
        }

        bool InputManager::isKeyDown(const Key &key) const
        {
            return keyState[key];
        }

        void InputManager::update(float ms)
        {
            SDL_Event event;
            while(SDL_PollEvent(&event)) {
                switch(event.type) {
                    /* Key down - alert all listeners. */
                    case SDL_KEYDOWN:
                        for(std::vector<KeyListener*>::iterator iterator =
                                keyListeners.begin();
                                iterator != keyListeners.end(); iterator++) {
                            (*iterator)->keyPressed((Key) event.key.keysym.sym);
                        }
                        break;
                    case SDL_QUIT:
                        quitEvent = true;
                        break;
                }
            }
        }

        void InputManager::addKeyListener(KeyListener *keyListener)
        {
            keyListeners.push_back(keyListener);
        }

        void InputManager::removeKeyListener(KeyListener *keyListener)
        {
            vector<KeyListener*>::iterator iterator = keyListeners.begin();
            bool removed = false;
            while(!removed && iterator != keyListeners.end()) {
                if(*iterator = keyListener) {
                    keyListeners.erase(iterator);
                    removed = true;
                } else {
                    iterator++;
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
