#include "PatrollingController.h"
#include "Entity.h"

#include "../math/Vector2D.h"
#include "../math/MathManager.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace game
    {
        void PatrollingController::loadData(TiXmlElement *element)
        {
            float tmp1, tmp2;
            element->QueryFloatAttribute("x1", &tmp1);
            element->QueryFloatAttribute("x2", &tmp2);
            x1 = MathManager::getInstance()->min(tmp1, tmp2);
            x2 = MathManager::getInstance()->max(tmp1, tmp2);
        }

        PatrollingController::PatrollingController(Entity *entity, float x1,
                float x2): Controller(entity)
        {
            this->x1 = MathManager::getInstance()->min(x1, x2);
            this->x2 = MathManager::getInstance()->max(x1, x2);
        }

        PatrollingController::PatrollingController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            load(element);
        }

        PatrollingController::~PatrollingController()
        {
        }

        void PatrollingController::affect(float ms)
        {
            Entity *entity = getEntity();
            Vector2D position = entity->getPosition();
            Vector2D velocity = entity->getVelocity();
            if(position.getX() < x1 && toX1) {
                toX1 = false;
            } else if(position.getX() > x2 && !toX1) {
                toX1 = true;
            } else {
                if(toX1)
                    velocity.setX(-entity->getSpeed());
                else
                    velocity.setX(entity->getSpeed());
            }

            entity->setVelocity(velocity);
        }
    }
}
