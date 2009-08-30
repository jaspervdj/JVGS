#include "FollowCamera.h"
#include "Entity.h"
#include "Level.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

#include "../video/VideoManager.h"
using namespace jvgs::video;

using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace game
    {
        void FollowCamera::loadData(TiXmlElement *element)
        {
            AbstractCamera::loadData(element);

            element->QueryFloatAttribute("maxdistance", &maxDistance);

            if(element->Attribute("target"))
                target = element->Attribute("target");

            Entity *entity = getLevel()->getEntityById(target);
            if(entity)
                setPosition(entity->getPosition());
        }

        FollowCamera::FollowCamera(const std::string &target, float maxDistance,
                Level *level): AbstractCamera(Vector2D(0.0f, 0.0f), level)
        {
            this->target = target;
            this->maxDistance = maxDistance;
        }

        FollowCamera::FollowCamera(TiXmlElement *element, Level *level)
                : AbstractCamera(element, level)
        {
            load(element);
        }

        FollowCamera::~FollowCamera()
        {
        }

        void FollowCamera::update(float ms)
        {
            Entity *entity = getLevel()->getEntityById(target);
            if(entity) {
                Vector2D entityToCamera = getPosition() - entity->getPosition();
                if(entityToCamera.getLength() > maxDistance) {
                    entityToCamera.setLength(maxDistance);
                    setPosition(entity->getPosition() + entityToCamera);
                }
            }
        }
    }
}
