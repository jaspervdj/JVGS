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
        }

        InputController::InputController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            load(element);
            InputManager::getInstance()->addKeyListener(this);
        }

        InputController::~InputController()
        {
            InputManager::getInstance()->removeKeyListener(this);
        }

        void InputController::affect(float ms)
        {
            Entity *entity = getEntity();
            Vector2D velocity = Vector2D();

            if(isKeyDown(KEY_LEFT))
                velocity.setX(-entity->getSpeed());
            else if(isKeyDown(KEY_RIGHT))
                velocity.setX(entity->getSpeed());

            if(isKeyDown(KEY_UP))
                velocity.setY(-entity->getSpeed());
            else if(isKeyDown(KEY_DOWN))
                velocity.setY(entity->getSpeed());

            entity->setVelocity(velocity);
        }

        void InputController::keyPressed(const Key &key)
        {
            if(key == KEY_LCTRL)
                EntityEvent::action(getEntity());
        }
    }
}
