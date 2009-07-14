#include "InputAffector.h"
#include "Entity.h"

using namespace jvgs::input;
using namespace jvgs::math;

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        InputAffector::InputAffector(Entity *entity, float speed):
                Affector(entity)
        {
            this->speed = speed;
        }

        InputAffector::~InputAffector()
        {
        }

        int InputAffector::getPriority() const
        {
            /* Very, very high. */
            return 100;
        }

        void InputAffector::affect(float ms)
        {
            Vector2D velocity = getEntity()->getVelocity();

            velocity.setX(isKeyDown(KEY_LEFT) ? -speed : 0.0f);
            velocity.setX(isKeyDown(KEY_RIGHT) ? speed : velocity.getX());

            if(isKeyDown(KEY_SPACE))
                velocity.setY(-5.0f * speed);

            getEntity()->setVelocity(velocity);
        }

        void InputAffector::keyPressed(const Key &key)
        {

        }
    }
}
