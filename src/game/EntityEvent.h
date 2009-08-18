#ifndef JVGS_GAME_ENTITYEVENT_H
#define JVGS_GAME_ENTITYEVENT_H

#include "../bind/ScriptManager.h"
#include <string>

namespace jvgs
{
    namespace game
    {
        class Entity;

        class EntityEvent
        {
            private:
                /** Script manager. */
                bind::ScriptManager *scriptManager;

                /** Source of the event. */
                Entity *source;

                /** Type of the event. */
                std::string type;

                /** The collider in case of a collision event. */
                Entity *collider;

            protected:
                /** Constructor.
                 */
                EntityEvent();

                /** Destructor.
                 */
                virtual ~EntityEvent();

            public:
                /** Get the event instance.
                 *  @return The event instance.
                 */
                static EntityEvent *getEvent();

                /** Get the event source.
                 *  @return The event source.
                 */
                Entity *getSource() const;

                /** Get the event type.
                 *  @return The event type.
                 */
                const std::string &getType() const;

                /** Get the collider. Only makes sense in case of a collision
                 *  event.
                 *  @return The collider.
                 */
                Entity *getCollider() const;

                /** Execute a collision event for both entities.
                 *  @param entity1 First colliding entity.
                 *  @param entity2 Second colliding entity.
                 */
                static void collision(Entity *entity1, Entity *entity2);

                /** Execute an action event for an entity.
                 *  @param entity Entity executing action.
                 */
                static void action(Entity *entity);

                /** Execute a spawn event for an entity.
                 *  @param entity Spawned entity.
                 */
                static void spawn(Entity *entity);

                /** Execute a die event for an entity.
                 *  @param entity Dying entity.
                 */
                static void die(Entity *entity);
        };
    }
}

#endif
