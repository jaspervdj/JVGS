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

                /** Minimum delay between jumps. */
                float minJumpDelay;

                /** Force to jump with. */
                float jumpForce;

                /** Delay to next jump. */
                float jumpDelay;

            public:
                /** Constructor.
                 *  @param speed Speed to move the entity with.
                 *  @param minJumpDelay Minimum delay between jumps.
                 *  @param jumpForce Force to jump with.
                 */
                InputController(Entity *entity, float speed,
                         float minJumpDelay, float jumpForce = 200.0f);

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
