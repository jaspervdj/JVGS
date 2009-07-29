#ifndef JVGS_GAME_POSITIONER_H
#define JVGS_GAME_POSITIONER_H

#include "Affector.h"

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

                /** Check if the entity can jump in the current position.
                 */
                virtual bool canJump(float ms) = 0;

                /* Override
                 */
                virtual void affect(float ms) = 0;
        };
    }
}

#endif
