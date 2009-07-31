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

                /** Delay to next jump. */
                float jumpDelay;

                /** General duration of a jump. */
                float jumpDuration;

                /** Height of a jump. */
                float jumpHeight;

            public:
                /** Constructor.
                 *  @param speed Speed to move the entity with.
                 *  @param jumpDuration General duration of a jump.
                 *  @param jumpHeight Height of a jump relative to gravity.
                 */
                InputController(Entity *entity, float speed,
                         float jumpDuration, float jumpHeight = 2.5f);

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
