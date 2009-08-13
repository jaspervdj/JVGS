#include "NaivePositioner.h"
#include "Entity.h"

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        void NaivePositioner::loadData(TiXmlElement *element)
        {
            Positioner::loadData(element);
        }

        NaivePositioner::NaivePositioner(Entity *entity)
                : Positioner(entity)
        {
        }

        NaivePositioner::NaivePositioner(Entity *entity, TiXmlElement *element)
                : Positioner(entity)
        {
            load(element);
        }

        NaivePositioner::~NaivePositioner()
        {
        }

        void NaivePositioner::affect(float ms)
        {
            Entity *entity = getEntity();
            entity->setFalling(true);
            Vector2D velocity = entity->getVelocity();
            entity->setPosition(entity->getPosition() + velocity * ms);
            velocity += getGravity() * ms;
            entity->setVelocity(velocity);
        }
    }
}
