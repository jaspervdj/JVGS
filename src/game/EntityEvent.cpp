#include "EntityEvent.h"
#include "Entity.h"

using namespace jvgs::bind;
using namespace std;

namespace jvgs
{
    namespace game
    {
        EntityEvent::EntityEvent(Entity *source, const string &type,
                Entity *collider, const string &key)
        {
            this->source = source;
            this->type = type;
            this->collider = collider;
            this->key = key;
        }

        EntityEvent::~EntityEvent()
        {
        }

        Entity *EntityEvent::getSource() const
        {
            return source;
        }

        const string &EntityEvent::getType() const
        {
            return type;
        }

        Entity *EntityEvent::getCollider() const
        {
            return collider;
        }

        const string &EntityEvent::getKey() const
        {
            return key;
        }
    }
}
