#ifndef JVGS_GAME_INPUTCONTROLLER_H
#define JVGS_GAME_INPUTCONTROLLER_H

#include "../math/Vector2D.h"
#include "../input/KeyListener.h"
#include "Controller.h"

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class InputController: public Controller, jvgs::input::KeyListener
        {
            private:
                /** Minimum delay between jumps. */
                float minJumpDelay;

                /** Force to jump with. */
                float jumpForce;

                /** Delay to next jump. */
                float jumpDelay;

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param minJumpDelay Minimum delay between jumps.
                 *  @param jumpForce Force to jump with.
                 */
                InputController(Entity *entity, float minJumpDelay,
                        float jumpForce = 200.0f);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                InputController(Entity *entity, TiXmlElement *element);

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
