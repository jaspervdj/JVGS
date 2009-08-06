#include "InputController.h"
#include "Entity.h"
#include "Positioner.h"

using namespace jvgs::input;
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace game
    {
        InputController::InputController(Entity *entity, float speed,
                float minJumpDelay, float jumpForce): Controller(entity)
        {
            this->speed = speed;
            this->minJumpDelay = minJumpDelay;
            this->jumpForce = jumpForce;
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

            velocity.setX(isKeyDown(KEY_LEFT) ? -speed : 0.0f);
            velocity.setX(isKeyDown(KEY_RIGHT) ? speed : velocity.getX());

            entity->setVelocity(velocity);
        }

        void InputController::keyPressed(const Key &key)
        {

        }
    }
}
