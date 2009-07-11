#ifndef JVGS_GAME_GRAVITYAFFECTOR_H
#define JVGS_GAME_GRAVITYAFFECTOR_H

#include "Affector.h"
#include "../math/Vector2D.h"

namespace jvgs
{
    namespace game
    {
        /** Affector affecting the entity by aplying gravity to it.
         */
        class GravityAffector: public Affector
        {
            private:
                /** The gravity vector. */
                math::Vector2D gravity;

            public:
                /** Constructor.
                 *  @param entity Entity to affect.
                 *  @param gravity Gravity vector to apply.
                 */
                GravityAffector(Entity *entity, const math::Vector2D &gravity);

                /** Destructor.
                 */
                virtual ~GravityAffector();

                /* Override
                 */
                virtual int getPriority() const;

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
