#ifndef JVGS_GAME_POSITIONER_H
#define JVGS_GAME_POSITIONER_H

#include "Affector.h"
#include "../math/Vector2D.h"

namespace jvgs
{
    namespace game
    {
        /** A class to apply velocity to an entity and to set the position.
         *  Also manages some entity - world interaction.
         */
        class Positioner: public Affector
        {
            public:
                /** Constructor.
                 *  @param entity Entity to position.
                 */
                Positioner(Entity *entity);

                /** Destructor.
                 */
                virtual ~Positioner();

                /* Override
                 */
                virtual void affect(float ms) = 0;

                /** Check if the entity can jump in the current position.
                 */
                virtual bool canJump(float ms) = 0;

                /** Get the gravity applied by the positioner.
                 *  @return The gravity.
                 */
                virtual math::Vector2D getGravity() const = 0;
        };
    }
}

#endif
