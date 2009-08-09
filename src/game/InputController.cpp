#include "InputController.h"
#include "Entity.h"
#include "Positioner.h"

#include "../tinyxml/tinyxml.h"

using namespace jvgs::input;
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace game
    {
        InputController::InputController(Entity *entity): Controller(entity)
        {
            /* Some defaults. */
            minJumpDelay = 200.0f;
            jumpForce = 50.0f;
            jumpDelay = 0.0f;
        }

        InputController::InputController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            element->QueryFloatAttribute("minJumpDelay", &minJumpDelay);
            element->QueryFloatAttribute("jumpForce", &jumpForce);
            jumpDelay = 0.0f;
        }
                

        InputController::~InputController()
        {
        }

        void InputController::affect(float ms)
        {
            Entity *entity = getEntity();
            Vector2D velocity = entity->getVelocity();
            Positioner *positioner = entity->getPositioner();

            /** In a jump. */
            if(jumpDelay > 0.0f)
                jumpDelay -= ms;

            /** Can start a jump. */
            if(!entity->isFalling() && isKeyDown(KEY_SPACE) &&
                    jumpDelay <= 0.0f) {
                jumpDelay = minJumpDelay;
                if(positioner)
                    velocity += positioner->getGravity() * -1.0f * jumpForce;
            }

            velocity.setX(isKeyDown(KEY_LEFT) ? -entity->getSpeed() : 0.0f);
            velocity.setX(isKeyDown(KEY_RIGHT) ? entity->getSpeed() :
                    velocity.getX());

            entity->setVelocity(velocity);
        }

        void InputController::keyPressed(const Key &key)
        {
        }

        void InputController::setMinJumpDelay(float minJumpDelay)
        {
            this->minJumpDelay = minJumpDelay;
        }

        void InputController::setJumpForce(float jumpForce)
        {
            this->jumpForce = jumpForce;
        }
    }
}
