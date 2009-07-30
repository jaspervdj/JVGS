#include "InputController.h"
#include "Entity.h"
#include "Positioner.h"

using namespace jvgs::input;
using namespace jvgs::math;

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        InputController::InputController(Entity *entity, float speed,
                float jumpDuration): Controller(entity)
        {
            this->speed = speed;
            this->jumpDuration = jumpDuration;
            jumpDelay = 0.0f;
        }

        InputController::~InputController()
        {
        }

        void InputController::affect(float ms)
        {
            Vector2D velocity(0.0f, 0.0f);
            Positioner *positioner = getEntity()->getPositioner();

            /** Can start a jump. */
            if(positioner) {
                if(jumpDelay <= 0.0f && isKeyDown(KEY_SPACE) &&
                        positioner->canJump(ms)) {
                    jumpDelay += jumpDuration;
                }
            }

            /** In a jump. */
            if(jumpDelay > 0.0f) {
                float factor = 2.0f / jumpDuration * jumpDelay - 1.0f;
                velocity = positioner->getJumpDirection() * factor * speed *
                        5.0f;
                jumpDelay -= ms;
            }

            velocity.setX(isKeyDown(KEY_LEFT) ? -speed : 0.0f);
            velocity.setX(isKeyDown(KEY_RIGHT) ? speed : velocity.getX());

            getEntity()->setVelocity(velocity);
        }

        void InputController::keyPressed(const Key &key)
        {

        }
    }
}
