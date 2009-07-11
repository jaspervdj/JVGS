#include "Entity.h"
#include "Affector.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <algorithm>
#include <iostream>
using namespace std;

using namespace jvgs::math;

/** Function to sort affectors based on priority.
 *  @param a1 First affector.
 *  @param a2 Second affector.
 *  @return If a1's priority is strictly higher than a2's priority.
 */
bool compareAffectors(jvgs::game::Affector *a1, jvgs::game::Affector *a2)
{
    return a1->getPriority() > a2->getPriority();
}

namespace jvgs
{
    namespace game
    {
        Entity::Entity()
        {
        }

        Entity::~Entity()
        {
            for(vector<Affector*>::iterator iterator = affectors.begin();
                    iterator != affectors.end(); iterator++)
                delete *iterator;
        }

        void Entity::prepare()
        {
            sort(affectors.begin(), affectors.end(), compareAffectors);
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

        void Entity::addAffector(Affector *affector)
        {
            if(affector->getEntity() != this)
                LogManager::getInstance()->error(
                        "Adding affector for entity a to entity b.");

            affectors.push_back(affector);
        }

        void Entity::update(float ms)
        {
            cout << "Updating entity:" << endl;
            /* Let the affectors affect this. */
            for(vector<Affector*>::iterator iterator = affectors.begin();
                    iterator != affectors.end(); iterator++) {
                (*iterator)->affect(ms);
            }
            cout << endl;

            position += velocity * ms;
        }
    }
}
