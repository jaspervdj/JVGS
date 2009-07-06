#include "Entity.h"

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        Entity::Entity()
        {
        }

        Entity::~Entity()
        {
        }

        const Vector2D &Entity::getPosition() const
        {
            return position;
        }

        void Entity::setPosition(const Vector2D &position)
        {
            this->position = position;
        }

        const Vector2D &Entity::getVelocity() const
        {
            return velocity;
        }

        void Entity::setVelocity(const Vector2D &velocity)
        {
            this->velocity = velocity;
        }

        const Ellipse &Entity::getEllipse() const
        {
            return ellipse;
        }

        void Entity::setEllipse(const Ellipse &ellipse)
        {
            this->ellipse = ellipse;
        }
    }
}
