#ifndef JVGS_GAME_DEFAULTINPUTCONTROLLER_H
#define JVGS_GAME_DEFAULTINPUTCONTROLLER_H

#include "../math/Vector2D.h"
#include "InputController.h"

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class DefaultInputController: public InputController
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
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 */
                DefaultInputController(Entity *entity);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                DefaultInputController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~DefaultInputController();

                /* Override.
                 */
                virtual void affect(float ms);

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
