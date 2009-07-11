#include "GravityAffector.h"
#include "Entity.h"

using namespace jvgs::math;

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        GravityAffector::GravityAffector(Entity *entity, 
                const Vector2D &gravity): Affector(entity)
        {
            this->gravity = gravity;
        }

        GravityAffector::~GravityAffector()
        {
        }

        int GravityAffector::getPriority() const
        {
            /* Medium priority. */
            return 10;
        }

        void GravityAffector::affect(float ms)
        {
            Vector2D velocity = getEntity()->getVelocity();
            velocity += gravity * ms;
            getEntity()->setVelocity(velocity);

            cout << "- gravity affected the entity." << endl;
            cout << "  -> (" << velocity.getX() << ", " << velocity.getY() <<
                    ")" << endl;
        }
    }
}
