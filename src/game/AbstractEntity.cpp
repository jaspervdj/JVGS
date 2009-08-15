#include "AbstractEntity.h"

using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace game
    {
        AbstractEntity::AbstractEntity(const std::string &id, Level *level)
        {
            this->id = id;
            this->level = level;
            garbage = false;
            position = Vector2D(0.0f, 0.0f);
            velocity = Vector2D(0.0f, 0.0f);
            speed = 0.3f;
        }

        AbstractEntity::~AbstractEntity()
        {
        }

        const string &AbstractEntity::getId() const
        {
            return id;
        }

        void AbstractEntity::setId(const string &id)
        {
            this->id = id;
        }

        Level *AbstractEntity::getLevel() const
        {
            return level;
        }

        bool AbstractEntity::isGarbage() const
        {
            return garbage;
        }

        void AbstractEntity::setGarbage()
        {
            garbage = true;
        }

        const Vector2D &AbstractEntity::getPosition() const
        {
            return position;
        }

        void AbstractEntity::setPosition(const Vector2D &position)
        {
            this->position = position;
        }

        const Vector2D &AbstractEntity::getVelocity() const
        {
            return velocity;
        }

        void AbstractEntity::setVelocity(const Vector2D &velocity)
        {
            this->velocity = velocity;
        }

        float AbstractEntity::getSpeed() const
        {
            return speed;
        }

        void AbstractEntity::setSpeed(float speed)
        {
            this->speed = speed;
        }
    }
}
