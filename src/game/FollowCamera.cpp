#include "FollowCamera.h"
#include "Entity.h"
#include "Level.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <string>
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
            element->QueryFloatAttribute("maxDistance", &maxDistance);
            string entityId = element->Attribute("entity");
            entity = level->getEntityById(entityId);
            if(entity)
                position = entity->getPosition();
            else
                LogManager::getInstance()->error("No entity called %s",
                        entityId.c_str());
        }

        FollowCamera::FollowCamera(Entity *entity, float maxDistance, Level *level)
        {
            this->level = level;
            this->entity = entity;
            this->maxDistance = maxDistance;
        }

        FollowCamera::FollowCamera(TiXmlElement *element, Level *level)
        {
            this->level = level;
            load(element);
        }

        FollowCamera::~FollowCamera()
        {
        }

        void FollowCamera::update(float ms)
        {
            Vector2D entityToCamera = position - entity->getPosition();
            if(entityToCamera.getLength() > maxDistance) {
                entityToCamera.setLength(maxDistance);
                position = entity->getPosition() + entityToCamera;
            }
        }

        void FollowCamera::transform() const
        {
            VideoManager *videoManager = VideoManager::getInstance();
            videoManager->translate(-position + videoManager->getSize() * 0.5f);
        }
    }
}
