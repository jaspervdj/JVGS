#ifndef JVGS_GAME_AFFECTOR_H
#define JVGS_GAME_AFFECTOR_H

#include "../core/XMLLoadable.h"

namespace jvgs
{
    namespace game
    {
        class Entity;

        /** A class that affects an entity. This could be used for gravity,
         *  controls, collision response, ...
         */
        class Affector: public core::XMLLoadable
        {
            private:
                Entity *entity;

            public:
                /** Constructor.
                 */
                Affector(Entity *entity);

                /** Destructor.
                 */
                virtual ~Affector();

                /** Get the affected entity.
                 *  @return The affected entity.
                 */
                virtual Entity *getEntity() const;

                /** Affect then entity.
                 *  @param ms Milliseconds to affect the entity.
                 */
                virtual void affect(float ms) = 0;
        };
    }
}

#endif
