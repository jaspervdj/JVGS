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
            private:
                /** Gravity pulling the entity. */
                math::Vector2D gravity;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

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

                /** Get the gravity applied by the positioner.
                 *  @return The gravity.
                 */
                virtual const math::Vector2D &getGravity() const;

                /** Set the gravity.
                 *  @param gravity The new gravity.
                 */
                virtual void setGravity(const math::Vector2D &gravity);

                /** Ask the positioner if the entity can jump.
                 *  @return If the entity can jump.
                 */
                virtual bool canJump();
        };
    }
}

#endif
