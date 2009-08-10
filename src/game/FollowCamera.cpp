#include "FollowCamera.h"
#include "Entity.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        FollowCamera::FollowCamera(Entity *entity, float maxDistance)
        {
            this->entity = entity;
            this->maxDistance = maxDistance;
            this->position = entity->getPosition();
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
