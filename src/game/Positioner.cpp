#include "Positioner.h"
#include "Entity.h"

#include "../tinyxml/tinyxml.h"

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        void Positioner::loadData(TiXmlElement *element)
        {
            Vector2D::fromXML(element->FirstChildElement("gravity"), &gravity);
        }

        Positioner::Positioner(Entity *entity): Affector(entity)
        {
        }

        Positioner::~Positioner()
        {
        }

        const Vector2D &Positioner::getGravity() const
        {
            return gravity;
        }

        void Positioner::setGravity(const Vector2D &gravity)
        {
            this->gravity = gravity;
        }

        bool Positioner::canJump()
        {
            return true;
        }
    }
}
