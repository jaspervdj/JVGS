#include "SillyController.h"
#include "Entity.h"

#include "../tinyxml/tinyxml.h"

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        void SillyController::loadData(TiXmlElement *element)
        {
            element->QueryFloatAttribute("speedtreshold", &speedTreshold);
        }

        SillyController::SillyController(Entity *entity, float speedTreshold)
                : Controller(entity)
        {
            this->speedTreshold = speedTreshold;
            walkingRight = true;
        }

        SillyController::SillyController(Entity *entity, TiXmlElement *element)
                : Controller(entity)
        {
            load(element);
            walkingRight = true;
        }

        SillyController::~SillyController()
        {
        }

        void SillyController::affect(float ms)
        {
            Entity *entity = getEntity();
            float speed = entity->getVelocity().getLength();
            if(speed < speedTreshold * entity->getSpeed()) {
                walkingRight = !walkingRight;
            }

            Vector2D velocity = entity->getVelocity();
            if(walkingRight)
                velocity.setX(entity->getSpeed());
            else
                velocity.setX(-entity->getSpeed());
            entity->setVelocity(velocity);
        }
    }
}
