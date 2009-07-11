#include "GravityAffector.h"
#include "Entity.h"

using namespace jvgs::math;

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
        }
    }
}
