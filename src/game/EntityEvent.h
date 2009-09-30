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
                /** Source of the event. */
                Entity *source;

                /** Type of the event. */
                std::string type;

                /** The collider in case of a collision event. */
                Entity *collider;

                /** The key in case of a property event. */
                std::string key;

            public:
                /** Constructor.
                 */
                EntityEvent(Entity *source, const std::string &type,
                        Entity *collider = 0, const std::string &key = "none");

                /** Destructor.
                 */
                virtual ~EntityEvent();

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

                /** Get the key in case of a property event.
                 *  @return The key.
                 */
                const std::string &getKey() const;
        };
    }
}

#endif
