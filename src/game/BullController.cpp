#include "BullController.h"
#include "Entity.h"
#include "Level.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

using namespace std;

namespace jvgs
{
    namespace game
    {
        void BullController::loadData(TiXmlElement *element)
        {
            if(element->Attribute("target"))
                target = element->Attribute("target");
            else
                LogManager::getInstance()->error(
                        "BullController must have a target.");

            element->QueryFloatAttribute("sight", &sight);
        }

        BullController::BullController(Entity *entity, const string &target,
                float sight): Controller(entity)
        {
            this->target = target;
            this->sight = sight;
        }

        BullController::BullController(Entity *entity, TiXmlElement *element)
                : Controller(entity)
        {
            load(element);
        }

        BullController::~BullController()
        {
        }

        void BullController::affect(float ms)
        {
            Entity *entity = getEntity();
            Level *level = entity->getLevel();
            Vector2D velocity = entity->getVelocity();
            if(level) {
                Entity *targetEntity = level->getEntityById(target);
                if(targetEntity) {
                    float distance = entity->getPosition().getDistance(
                            targetEntity->getPosition());
                    if(distance <= sight) {
                        Vector2D toTarget = targetEntity->getPosition() -
                            entity->getPosition();
                        toTarget.setLength(entity->getSpeed());
                        velocity.setX(toTarget.getX());
                    }
                }
            }

            entity->setVelocity(velocity);
        }
    }
}
