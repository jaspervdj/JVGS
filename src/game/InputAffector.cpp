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
        InputAffector::InputAffector(Entity *entity): Affector(entity)
        {
            speed = 2.0f;
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
            velocity = Vector2D(0.0f, 0.0f);

            if(isKeyDown(KEY_DOWN))
                velocity.setY(1.0f);
            else if(isKeyDown(KEY_UP))
                velocity.setY(-1.0f);
            else if(isKeyDown(KEY_LEFT))
                velocity.setX(-1.0f);
            else if(isKeyDown(KEY_RIGHT))
                velocity.setX(1.0f);

            velocity.setLength(speed);
            getEntity()->setVelocity(velocity);

            cout << "- input affected the entity." << endl;
            cout << "  -> (" << velocity.getX() << ", " << velocity.getY() <<
                    ")" << endl;
        }

        void InputAffector::keyPressed(const Key &key)
        {

        }
    }
}
