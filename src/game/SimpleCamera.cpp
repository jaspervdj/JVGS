#include "SimpleCamera.h"

using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace game
    {
        void SimpleCamera::loadData(TiXmlElement *element)
        {
            AbstractCamera::loadData(element);
            Vector2D::fromXML(element->FirstChildElement("velocity"),
                    &velocity);
        }

        SimpleCamera::SimpleCamera(const Vector2D &position,
                const Vector2D &velocity, Level *level)
                : AbstractCamera(position, level)
        {
            this->velocity = velocity;
        }

        SimpleCamera::SimpleCamera(TiXmlElement *element, Level *level)
                : AbstractCamera(element, level)
        {
            load(element);
        }

        SimpleCamera::~SimpleCamera()
        {
        }

        const Vector2D &SimpleCamera::getVelocity() const
        {
            return velocity;
        }

        void SimpleCamera::setVelocity(const Vector2D &velocity)
        {
            this->velocity = velocity;
        }

        void SimpleCamera::update(float ms)
        {
            setPosition(getPosition() + velocity * ms);
        }
    }
}
