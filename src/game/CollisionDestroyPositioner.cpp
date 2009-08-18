#include "CollisionDestroyPositioner.h"
#include "Level.h"
#include "Entity.h"

#include "../math/CollisionDetector.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        void CollisionDestroyPositioner::loadData(TiXmlElement *element)
        {
            Positioner::loadData(element);
        }

        CollisionDestroyPositioner::CollisionDestroyPositioner(Entity *entity)
                : Positioner(entity)
        {
        }

        CollisionDestroyPositioner::CollisionDestroyPositioner(Entity *entity,
                TiXmlElement *element): Positioner(entity)
        {
            load(element);
        }

        CollisionDestroyPositioner::~CollisionDestroyPositioner()
        {
        }

        void CollisionDestroyPositioner::affect(float ms)
        {
            Entity *entity = getEntity();
            CollisionDetector *collisionDetector =
                    entity->getLevel()->getCollisionDetector();

            /* Convert vectors to ellipse space. */
            Vector2D position = entity->getPosition();
            Vector2D velocity = entity->getVelocity() * ms;

            /* Used later. */
            float time;
            Vector2D collision;

            if(collisionDetector->getClosestCollision(
                    entity->getRadius(), position, velocity,
                    &time, &collision)) {
                entity->setGarbage();
                entity->setPosition(collision);
            } else {
                entity->setPosition(position + velocity);
            }

            velocity = entity->getVelocity() + getGravity() * ms;
            entity->setVelocity(velocity);
        }
    }
}
