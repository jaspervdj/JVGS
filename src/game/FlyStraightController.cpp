#include "FlyStraightController.h"
#include "Entity.h"
#include "Level.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace game
    {
        void FlyStraightController::loadData(TiXmlElement *element)
        {
        }

        FlyStraightController::FlyStraightController(Entity *entity)
                : Controller(entity)
        {
        }

        FlyStraightController::FlyStraightController(Entity *entity,
                TiXmlElement *element): Controller(entity)
        {
            load(element);
        }

        FlyStraightController::~FlyStraightController()
        {
        }

        void FlyStraightController::affect(float ms)
        {
        }
    }
}
