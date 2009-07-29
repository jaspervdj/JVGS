#include "InputController.h"
#include "Entity.h"

using namespace jvgs::input;
using namespace jvgs::math;

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        InputController::InputController(Entity *entity, float speed):
                Controller(entity)
        {
            this->speed = speed;
        }

        InputController::~InputController()
        {
        }

        void InputController::affect(float ms)
        {
            Vector2D velocity;

            velocity.setX(isKeyDown(KEY_LEFT) ? -speed : 0.0f);
            velocity.setX(isKeyDown(KEY_RIGHT) ? speed : velocity.getX());

            getEntity()->setVelocity(velocity);
        }

        void InputController::keyPressed(const Key &key)
        {

        }
    }
}
