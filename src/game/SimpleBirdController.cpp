#include "SimpleBirdController.h"
#include "Entity.h"

#include "../tinyxml/tinyxml.h"

using namespace std;
using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        void SimpleBirdController::loadData(TiXmlElement *element)
        {
            TiXmlElement *pointElement = element->FirstChildElement("point");
            while(pointElement) {
                Vector2D point;
                Vector2D::fromXML(pointElement, &point);
                addPoint(point);
                pointElement = pointElement->NextSiblingElement("point");
            }
        }

        SimpleBirdController::SimpleBirdController(Entity *entity)
                : Controller(entity)
        {
            currentPoint = -1;
        }

        SimpleBirdController::SimpleBirdController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            currentPoint = -1;
            load(element);
        }

        SimpleBirdController::~SimpleBirdController()
        {
        }

        void SimpleBirdController::addPoint(const Vector2D &point)
        {
            if(currentPoint < 0)
                currentPoint = 0;
            points.push_back(point);
        }

        void SimpleBirdController::affect(float ms)
        {
            Entity *entity = getEntity();
            if(currentPoint >= 0) {
                Vector2D position = entity->getPosition();
                Vector2D target = points[currentPoint];
                Vector2D velocity = target - position;
                velocity.setLength(entity->getSpeed());
                Vector2D destination = position + velocity * ms;

                /* We cross the target. */
                if(destination.getDistance(target) >
                        position.getDistance(target) ||
                        position.getDistance(target) < 0.00001f)
                    currentPoint = (currentPoint + 1) % points.size();

                entity->setVelocity(velocity);
            }
        }
    }
}
