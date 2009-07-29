#include "Entity.h"
#include "Controller.h"
#include "Positioner.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <iostream>
using namespace std;

using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        Entity::Entity()
        {
            controller = 0;
            positioner = 0;
        }

        Entity::~Entity()
        {
            if(controller)
                delete controller;
            if(positioner)
                delete positioner;
        }

        const Vector2D &Entity::getPosition() const
        {
            return position;
        }

        void Entity::setPosition(const Vector2D &position)
        {
            this->position = position;
        }

        const Vector2D &Entity::getVelocity() const
        {
            return velocity;
        }

        void Entity::setVelocity(const Vector2D &velocity)
        {
            this->velocity = velocity;
        }

        const Vector2D &Entity::getEllipse() const
        {
            return ellipse;
        }

        void Entity::setEllipse(const Vector2D &ellipse)
        {
            this->ellipse = ellipse;
        }

        void Entity::setController(Controller *controller)
        {
            if(this->controller)
                delete this->controller;
            this->controller = controller;
        }

        Controller *Entity::getController() const
        {
            return controller;
        }

        void Entity::setPositioner(Positioner *positioner)
        {
            if(this->positioner)
                delete this->positioner;
            this->positioner = positioner;
        }

        Positioner *Entity::getPositioner() const
        {
            return positioner;
        }

        void Entity::update(float ms)
        {
            if(controller)
                controller->affect(ms);
            if(positioner)
                positioner->affect(ms);
        }
    }
}
