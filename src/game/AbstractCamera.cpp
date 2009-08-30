#include "AbstractCamera.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace game
    {
        void AbstractCamera::loadData(TiXmlElement *element)
        {
            Vector2D::fromXML(element->FirstChildElement("position"),
                    &position);
        }

        AbstractCamera::AbstractCamera(const Vector2D &position, Level *level)
                : Camera(level)
        {
            this->position = position;
        }

        AbstractCamera::AbstractCamera(TiXmlElement *element, Level *level)
                : Camera(level)
        {
            load(element);
        }

        AbstractCamera::~AbstractCamera()
        {
        }

        const Vector2D &AbstractCamera::getPosition() const
        {
            return position;
        }

        void AbstractCamera::setPosition(const Vector2D &position)
        {
            this->position = position;
        }

        void AbstractCamera::transform() const
        {
            VideoManager *videoManager = VideoManager::getInstance();
            videoManager->translate(-position + videoManager->getSize() * 0.5f);
        }

        BoundingBox *AbstractCamera::getBoundingBox()
        {
            VideoManager *videoManager = VideoManager::getInstance();
            boundingBox = BoundingBox(position - videoManager->getSize() * 0.5f,
                    position + videoManager->getSize() * 0.5f);
            return &boundingBox;
        }
    }
}
