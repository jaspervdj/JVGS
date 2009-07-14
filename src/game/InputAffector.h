#ifndef JVGS_GAME_INPUTAFFECTOR_H
#define JVGS_GAME_INPUTAFFECTOR_H

#include "../math/Vector2D.h"
#include "../input/KeyListener.h"
#include "Affector.h"

namespace jvgs
{
    namespace game
    {
        class InputAffector: public Affector, jvgs::input::KeyListener
        {
            private:
                /** Speed to move the entity with. */
                float speed;

            public:
                /** Constructor.
                 *  @param speed Speed to move the entity with.
                 */
                InputAffector(Entity *entity, float speed);

                /** Destructor.
                 */
                virtual ~InputAffector();

                /* Override.
                 */
                virtual int getPriority() const;

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
