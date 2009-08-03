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
                float jumpDuration, float jumpHeight): Controller(entity)
        {
            this->speed = speed;
            this->jumpDuration = jumpDuration;
            this->jumpHeight = jumpHeight;
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
            Vector2D collision;
            if(positioner) {
                if(isKeyDown(KEY_SPACE) &&
                        positioner->hasNearCollision(ms, &collision)) {
                    jumpDelay = jumpDuration;
                }
            }

            /** In a jump. */
            if(jumpDelay > 0.0f) {
                float factor = jumpHeight / jumpDuration * jumpDelay;
                velocity = positioner->getGravity() * -1.0f * factor;
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
