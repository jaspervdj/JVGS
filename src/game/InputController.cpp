#include "InputController.h"
#include "Entity.h"
#include "EntityEventManager.h"

#include "../input/InputManager.h"
using namespace jvgs::input;

#include "../tinyxml/tinyxml.h"

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        void InputController::loadData(TiXmlElement *element)
        {
        }

        InputController::InputController(Entity *entity)
                : Controller(entity)
        {
            configuration = InputConfiguration::getConfiguration();
            inputManager = InputManager::getInstance();
        }

        InputController::InputController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            load(element);
            configuration = InputConfiguration::getConfiguration();
            inputManager = InputManager::getInstance();
        }

        InputController::~InputController()
        {
        }

        void InputController::affect(float ms)
        {
            Entity *entity = getEntity();
            Vector2D velocity = Vector2D();

            if(inputManager->isKeyDown(configuration->getKey("left")))
                velocity.setX(-entity->getSpeed());
            else if(inputManager->isKeyDown(configuration->getKey("right")))
                velocity.setX(entity->getSpeed());

            if(inputManager->isKeyDown(configuration->getKey("up")))
                velocity.setY(-entity->getSpeed());
            else if(inputManager->isKeyDown(configuration->getKey("down")))
                velocity.setY(entity->getSpeed());

            if(inputManager->isKeyTicked(configuration->getKey("action")))
                EntityEventManager::getInstance()->action(entity);

            entity->setVelocity(velocity);
        }
    }
}
