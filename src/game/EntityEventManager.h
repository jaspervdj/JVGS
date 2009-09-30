#ifndef JVGS_GAME_ENTITYEVENTMANAGER_H
#define JVGS_GAME_ENTITYEVENTMANAGER_H

#include <queue>
#include "../bind/ScriptManager.h"

namespace jvgs
{
    namespace game
    {
        class Entity;
        class EntityEvent;

        class EntityEventManager
        {
            private:
                /** Script manager. */
                bind::ScriptManager *scriptManager;

                /** Event queue. */
                std::queue<EntityEvent*> events;

                /** The next event. */
                EntityEvent *pendingEvent;

            protected:
                /** Constructor.
                 */
                EntityEventManager();

                /** Destructor.
                 */
                virtual ~EntityEventManager();

            public:
                /** Get the manager instance.
                 *  @return The manager instance.
                 */
                static EntityEventManager *getInstance();

                /** Obtain the pending event.
                 *  @return The pending event.
                 */
                EntityEvent *getPendingEvent() const;

                /** Execute a collision event for both entities.
                 *  @param entity1 First colliding entity.
                 *  @param entity2 Second colliding entity.
                 */
                void collision(Entity *entity1, Entity *entity2);

                /** Execute an action event for an entity.
                 *  @param entity Entity executing action.
                 */
                void action(Entity *entity);

                /** Execute a spawn event for an entity.
                 *  @param entity Spawned entity.
                 */
                void spawn(Entity *entity);

                /** Execute a die event for an entity.
                 *  @param entity Dying entity.
                 */
                void die(Entity *entity);

                /** Execute a timer event for an entity.
                 *  @param entity Entity holding the timer.
                 */
                void timer(Entity *entity);

                /** Execute a property change event for an entity.
                 *  @param entity Entity which properties are changed.
                 *  @param propery Name of the property that is changed.
                 */
                void property(Entity *entity, const std::string &key);

                /** Flush all pending events.
                 */
                void flush();
        };
    }
}

#endif
