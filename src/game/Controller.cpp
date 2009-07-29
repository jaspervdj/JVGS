#include "Controller.h"
#include "Entity.h"

namespace jvgs
{
    namespace game
    {
        Controller::Controller(Entity *entity): Affector(entity)
        {
        }

        Controller::~Controller()
        {
        }
    }
}
