#ifndef JVGS_GAME_ENTITY_H
#define JVGS_GAME_ENTITY_H

#include "../math/Vector2D.h"
#include <vector>

namespace jvgs
{
    namespace game
    {
        class Affector;

        class Entity
        {
            private:
                /** The entity position.
                 */
                math::Vector2D position;

                /** The entity velocity.
                 */
                math::Vector2D velocity;

                /** Ellipse used for collision detection.
                 */
                math::Vector2D ellipse;

                /** A list of affectors for this entity.
                 */
                std::vector<Affector*> affectors;

            public:
                /** Constructor.
                 */
                Entity();

                /** Destructor.
                 */
                virtual ~Entity();

                /** Prepare the entity to be launched into the game. This will
                 *  do some things like sorting the affectors, ...
                 */
                virtual void prepare();

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

                /** Get the ellipse used for collision detection.
                 *  @return The ellipse used for collision detection.
                 */
                virtual const math::Vector2D &getEllipse() const;

                /** Set the ellipse used for collision detection.
                 *  @param ellipse The new ellipse.
                 */
                virtual void setEllipse(const math::Vector2D &ellipse);

                /** Add an affector to this entity. The entity will now
                 *  take care of the affector and delete it later.
                 *  @param affector Affector to add.
                 */
                virtual void addAffector(Affector *affector);

                /** Update this entity for a given time.
                 *  @param ms Time to update for.
                 */
                virtual void update(float ms);
        };
    }
}

#endif
