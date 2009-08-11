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

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 */
                InputController(Entity *entity);

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

                /** Set the minimum jump delay.
                 *  @param The minimum jump delay.
                 */
                void setMinJumpDelay(float minJumpDelay);

                /** Set the jump force.
                 *  @param jumpForce Force to jump with.
                 */
                void setJumpForce(float jumpForce);
        };
    }
}

#endif
