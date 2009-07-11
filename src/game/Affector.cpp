#include "Affector.h"
#include "Entity.h"

namespace jvgs
{
    namespace game
    {
        Affector::Affector(Entity *entity)
        {
            this->entity = entity;
        }

        Affector::~Affector()
        {
        }

        Entity *Affector::getEntity() const
        {
            return entity;
        }
    }
}
