#ifndef JVGS_GAME_INPUTCONTROLLER_H
#define JVGS_GAME_INPUTCONTROLLER_H

#include "../math/Vector2D.h"
#include "../input/KeyListener.h"
#include "Controller.h"

namespace jvgs
{
    namespace game
    {
        class InputController: public Controller, jvgs::input::KeyListener
        {
            private:
                /** Speed to move the entity with. */
                float speed;

            public:
                /** Constructor.
                 *  @param speed Speed to move the entity with.
                 */
                InputController(Entity *entity, float speed);

                /** Destructor.
                 */
                virtual ~InputController();

                /* Override.
                 */
                virtual void affect(float ms);

                /* Override.
                 */
                virtual void keyPressed(const jvgs::input::Key &key);
        };
    }
}

#endif
