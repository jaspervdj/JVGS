#include "EntityEventManager.h"
#include "EntityEvent.h"
#include "Entity.h"

using namespace jvgs::bind;
using namespace std;

namespace jvgs
{
    namespace game
    {
        EntityEventManager::EntityEventManager()
        {
            scriptManager = ScriptManager::getInstance();
        }

        EntityEventManager::~EntityEventManager()
        {
        }

        EntityEventManager *EntityEventManager::getInstance()
        {
            static EntityEventManager instance;
            return &instance;
        }

        EntityEvent *EntityEventManager::getPendingEvent() const
        {
            return pendingEvent;
        }

        void EntityEventManager::collision(Entity *entity1, Entity *entity2)
        {
            events.push(new EntityEvent(entity1, "collision", entity2));
            events.push(new EntityEvent(entity2, "collision", entity1));
        }

        void EntityEventManager::action(Entity *entity)
        {
            events.push(new EntityEvent(entity, "action"));
        }

        void EntityEventManager::spawn(Entity *entity)
        {
            events.push(new EntityEvent(entity, "spawn"));
        }

        void EntityEventManager::die(Entity *entity)
        {
            events.push(new EntityEvent(entity, "die"));
        }

        void EntityEventManager::timer(Entity *entity)
        {
            events.push(new EntityEvent(entity, "timer"));
        }

        void EntityEventManager::property(Entity *entity, const string &key)
        {
            events.push(new EntityEvent(entity, "property", 0, key));
        }

        void EntityEventManager::flush()
        {
            while(!events.empty()) {
                pendingEvent = events.front();
                scriptManager->runScript(
                        pendingEvent->getSource()->getScript());
                events.pop();
                delete pendingEvent;
            }
        }
    }
}
