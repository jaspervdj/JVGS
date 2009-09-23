#include "InputController.h"
#include "Entity.h"
#include "EntityEvent.h"

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
            InputManager::getInstance()->addKeyListener(this);
            configuration = InputConfiguration::getConfiguration();
        }

        InputController::InputController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            load(element);
            InputManager::getInstance()->addKeyListener(this);
            configuration = InputConfiguration::getConfiguration();
        }

        InputController::~InputController()
        {
            InputManager::getInstance()->removeKeyListener(this);
        }

        void InputController::affect(float ms)
        {
            Entity *entity = getEntity();
            Vector2D velocity = Vector2D();

            if(isKeyDown(configuration->getKey("left")))
                velocity.setX(-entity->getSpeed());
            else if(isKeyDown(configuration->getKey("right")))
                velocity.setX(entity->getSpeed());

            if(isKeyDown(configuration->getKey("up")))
                velocity.setY(-entity->getSpeed());
            else if(isKeyDown(configuration->getKey("down")))
                velocity.setY(entity->getSpeed());

            entity->setVelocity(velocity);
        }

        void InputController::keyPressed(const Key &key)
        {
            if(key == configuration->getKey("action"))
                EntityEvent::action(getEntity());
        }
    }
}
