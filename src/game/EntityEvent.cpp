#include "EntityEvent.h"
#include "Entity.h"

using namespace jvgs::bind;
using namespace std;

namespace jvgs
{
    namespace game
    {
        EntityEvent::EntityEvent()
        {
            scriptManager = ScriptManager::getInstance();
        }

        EntityEvent::~EntityEvent()
        {
        }

        EntityEvent *EntityEvent::getEvent()
        {
            static EntityEvent event;
            return &event;
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

        void EntityEvent::collision(Entity *entity1, Entity *entity2)
        {
            EntityEvent *event = getEvent();
            event->type = "collision";
            event->source = entity1;
            event->collider = entity2;
            event->scriptManager->runScript(entity1->getScript());

            event->source = entity2;
            event->collider = entity1;
            event->scriptManager->runScript(entity2->getScript());
        }

        void EntityEvent::action(Entity *entity)
        {
            EntityEvent *event = getEvent();
            event->type = "action";
            event->source = entity;
            event->scriptManager->runScript(entity->getScript());
        }

        void EntityEvent::spawn(Entity *entity)
        {
            EntityEvent *event = getEvent();
            event->type = "spawn";
            event->source = entity;
            event->scriptManager->runScript(entity->getScript());
        }

        void EntityEvent::die(Entity *entity)
        {
            EntityEvent *event = getEvent();
            event->type = "die";
            event->source = entity;
            event->scriptManager->runScript(entity->getScript());
        }
    }
}
