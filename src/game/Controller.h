#ifndef JVGS_GAME_CONTROLLER_H
#define JVGS_GAME_CONTROLLER_H

#include "Affector.h"

namespace jvgs
{
    namespace game
    {
        /** A class that controls an entity, eg. sets it's velocity.
         */
        class Controller: public Affector
        {
            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 */
                Controller(Entity *entity);

                /** Destructor.
                 */
                virtual ~Controller();

                /* Override
                 */
                virtual void affect(float ms) = 0;
        };
    }
}

#endif
