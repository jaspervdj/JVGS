#include "DefaultInputController.h"
#include "Entity.h"
#include "EntityEvent.h"
#include "EntityEventManager.h"
#include "Positioner.h"

#include "../input/InputManager.h"
using namespace jvgs::input;

#include "../tinyxml/tinyxml.h"

using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace game
    {
        void DefaultInputController::loadData(TiXmlElement *element)
        {
            element->QueryFloatAttribute("minjumpdelay", &minJumpDelay);
            element->QueryFloatAttribute("jumpforce", &jumpForce);
        }

        DefaultInputController::DefaultInputController(Entity *entity)
                : InputController(entity)
        {
            /* Some defaults. */
            minJumpDelay = 200.0f;
            jumpForce = 50.0f;
            jumpDelay = 0.0f;
        }

        DefaultInputController::DefaultInputController(Entity *entity,
                TiXmlElement *element): InputController(entity)
        {
            jumpDelay = 0.0f;
            load(element);
        }

        DefaultInputController::~DefaultInputController()
        {
        }

        void DefaultInputController::affect(float ms)
        {
            Entity *entity = getEntity();
            Vector2D velocity = entity->getVelocity();
            Positioner *positioner = entity->getPositioner();

            /** In a jump. */
            if(jumpDelay > 0.0f)
                jumpDelay -= ms;

            /** Can start a jump. */
            if(positioner) {
                if(inputManager->isKeyDown(configuration->getKey("jump")) &&
                        positioner->canJump() && jumpDelay <= 0.0f) {
                    jumpDelay = minJumpDelay;
                    velocity = positioner->getGravity() * -1.0f * jumpForce;
                }
            }

            if(inputManager->isKeyDown(configuration->getKey("left")))
                velocity.setX(-entity->getSpeed());
            else if(inputManager->isKeyDown(configuration->getKey("right")))
                velocity.setX(entity->getSpeed());
            else
                velocity.setX(0.0f);

            if(inputManager->isKeyTicked(configuration->getKey("action")))
                EntityEventManager::getInstance()->action(entity);

            entity->setVelocity(velocity);
        }

        void DefaultInputController::setMinJumpDelay(float minJumpDelay)
        {
            this->minJumpDelay = minJumpDelay;
        }

        void DefaultInputController::setJumpForce(float jumpForce)
        {
            this->jumpForce = jumpForce;
        }
    }
}
