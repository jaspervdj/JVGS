#ifndef JVGS_GAME_ABSTRACTENTITY_H
#define JVGS_GAME_ABSTRACTENTITY_H

#include "../math/Vector2D.h"
#include "../core/View.h"
#include <string>

namespace jvgs
{
    namespace game
    {
        class Level;

        class AbstractEntity: public core::View
        {
            private:
                /** Entity id. */
                std::string id;

                /** Level the entity is in. */
                Level *level;

                /** The entity position. */
                math::Vector2D position;

                /** The entity velocity. */
                math::Vector2D velocity;

                /** Speed of the entity. */
                float speed;

            public:
                /** Constructor.
                 *  @param id Id for the entity.
                 *  @param level Level the entity is in.
                 */
                AbstractEntity(const std::string &id, Level *level);

                /** Destructor.
                 */
                virtual ~AbstractEntity();

                /** Get the entity id.
                 *  @return The id for this entity.
                 */
                virtual const std::string &getId() const;

                /** Set the entity id. Use with care.
                 *  @param id The new id.
                 */
                virtual void setId(const std::string &id);

                /** Get the entity level.
                 *  @return The level the entity is in.
                 */
                virtual Level *getLevel() const;

                /** Get the entity position.
                 *  @return The entity position.
                 */
                virtual const math::Vector2D &getPosition() const;

                /** Set the entity position.
                 *  @param position The new entity position.
                 */
                virtual void setPosition(const math::Vector2D &position);

                /** Get the entity velocity.
                 *  @return The entity velocity.
                 */
                virtual const math::Vector2D &getVelocity() const;

                /** Set the entity velocity.
                 *  @param velocity The new entity velocity.
                 */
                virtual void setVelocity(const math::Vector2D &velocity);

                /** Get the speed for this entity.
                 *  @return The speed for this entity.
                 */
                virtual float getSpeed() const;

                /** Set the speed for this entity.
                 *  @param speed The new speed for this entity.
                 */
                virtual void setSpeed(float speed);
        };
    }
}

#endif
