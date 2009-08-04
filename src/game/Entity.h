#ifndef JVGS_GAME_ENTITY_H
#define JVGS_GAME_ENTITY_H

#include "../math/Vector2D.h"
#include <vector>

namespace jvgs
{
    namespace game
    {
        class Controller;
        class Positioner;
        class Sprite;

        class Entity
        {
            private:
                /** The entity position. */
                math::Vector2D position;

                /** The entity velocity. */
                math::Vector2D velocity;

                /** Ellipse used for collision detection. */
                math::Vector2D ellipse;

                /** If the entity is falling. */
                bool falling;

                /** If the entity is slipping. */
                bool slipping;

                /** Entity controller. */
                Controller *controller;

                /** Entity positioner. */
                Positioner *positioner;

                /** Entity sprite. */
                Sprite *sprite;

            public:
                /** Constructor.
                 */
                Entity();

                /** Destructor.
                 */
                virtual ~Entity();

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

                /** Check if the entity is falling.
                 *  @return If the entity is falling.
                 */
                virtual bool isFalling() const;

                /** Set the falling state.
                 *  @param falling If the entity is falling.
                 */
                virtual void setFalling(bool falling);

                /** Check if the entity is slipping.
                 *  @return If the entity is slipping.
                 */
                virtual bool isSlipping() const;

                /** Set the slipping state.
                 *  @param slipping If the entity is slipping.
                 */
                virtual void setSlipping(bool slipping);

                /** Set the controller of this entity.
                 *  @param controller The controller of this entity.
                 */
                virtual void setController(Controller *controller);

                /** Get the controller of this entity.
                 *  @return The controller of this entity.
                 */
                virtual Controller *getController() const;

                /** Set the positioner of this entity.
                 *  @param positioner The positioner of this entity.
                 */
                virtual void setPositioner(Positioner *positioner);

                /** Get the positioner of this entity.
                 *  @return The positioner of this entity.
                 */
                virtual Positioner *getPositioner() const;

                /** Set the sprite of this entity.
                 *  @param sprite The sprite of this entity.
                 */
                virtual void setSprite(Sprite *sprite);

                /** Get the sprite of this entity.
                 *  @return The sprite of this entity.
                 */
                virtual Sprite *getSprite() const;

                /** Update this entity for a given time.
                 *  @param ms Time to update for.
                 */
                virtual void update(float ms);

                /** Render this entity to the screen.
                 */
                virtual void render();
        };
    }
}

#endif
