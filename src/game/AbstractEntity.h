#ifndef JVGS_GAME_ABSTRACTENTITY_H
#define JVGS_GAME_ABSTRACTENTITY_H

#include "../math/Vector2D.h"
#include <string>

namespace jvgs
{
    namespace game
    {
        class Level;

        class AbstractEntity
        {
            private:
                /** Entity id. */
                std::string id;

                /** Level the entity is in. */
                Level *level;

                /** If the entity is garbage and should be removed. */
                bool garbage;

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

                /** See if this object is garbage. When garbage, it should be
                 *  removed.
                 *  @return If this entity is garbage.
                 */
                virtual bool isGarbage() const;

                /** Mark this entity as being garbage. It will be removed later.
                 */
                virtual void setGarbage();

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

                /** Update this entity for a given time.
                 *  @param ms Time to update for.
                 */
                virtual void update(float ms) = 0;

                /** Render this entity to the screen.
                 */
                virtual void render() = 0;
        };
    }
}

#endif
