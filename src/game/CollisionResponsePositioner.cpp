#include "CollisionResponsePositioner.h"
#include "Entity.h"
#include "Level.h"

#include "../input/InputManager.h"
using namespace jvgs::input;

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../math/PathSegment.h"
#include "../math/BoundingBox.h"
#include "../math/Vector2D.h"
#include "../math/Line.h"
#include "../math/QuadTree.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

using namespace std;

namespace jvgs
{
    namespace game
    {
        const float CollisionResponsePositioner::VERY_CLOSE;
        const int CollisionResponsePositioner::MAX_STEPS;
        const float CollisionResponsePositioner::SLIP_LIMIT;

        void CollisionResponsePositioner::loadData(TiXmlElement *element)
        {
            gravity = Vector2D(element->FirstChildElement("gravity"));
        }

        CollisionResponsePositioner::CollisionResponsePositioner(
                Entity *entity): Positioner(entity)
        {
            Sketch *world = entity->getLevel()->getWorld();
            collisionDetector = new CollisionDetector(world);
            gravity = Vector2D(0.0f, 0.0f);
        }

        CollisionResponsePositioner::CollisionResponsePositioner(Entity *entity,
                TiXmlElement *element): Positioner(entity)
        {
            Sketch *world = entity->getLevel()->getWorld();
            collisionDetector = new CollisionDetector(world);
            load(element);
        }

        CollisionResponsePositioner::~CollisionResponsePositioner()
        {
            delete collisionDetector;
        }

        void CollisionResponsePositioner::affect(float ms)
        {
            Entity *entity = getEntity();

            /* Store the original ms. */
            float timeLeft = 1.0f;

            /* Convert vectors to ellipse space. */
            Vector2D position = entity->getPosition();
            Vector2D velocity = entity->getVelocity() * ms;

            /* Used later. */
            Vector2D destination;
            float time;
            Vector2D collision;

            int collisionSteps = 0;
            while(collisionSteps < MAX_STEPS && timeLeft > 0 &&
                    velocity.getLength() > VERY_CLOSE) {

                /* Update destination. */
                destination = position + velocity;

                /* A collision occurred. */
                if(collisionDetector->getClosestCollision(
                        entity->getRadius(), position, velocity,
                        &time, &collision)) {
                    Vector2D newPosition = position;

                    /* Only update above a certain distance. */
                    float distance = (velocity * time).getLength();
                    if(distance >= VERY_CLOSE) {
                        Vector2D v = velocity;
                        v.setLength(distance - VERY_CLOSE);
                        newPosition = position + v;
                    }

                    /* Subtract used velocity. */
                    velocity *= (1.0f - time);

                    /* Add a normal force. */
                    Vector2D normalForce = position - collision;
                    normalForce.setLength(velocity.getLength());
                    velocity += normalForce;
 
                    /* Update the time and position. */
                    position = newPosition;
                    timeLeft -= time;

                /* No collision, just update position. */
                } else {
                    position = destination;
                    timeLeft = 0.0f;
                }

                /* Keep track of the steps. */
                collisionSteps++;
            }

            if(collisionSteps >= MAX_STEPS)
                velocity = Vector2D(0.0f, 0.0f);

            /* Convert velocity back to original scale. */
            velocity *= (1.0f / ms);

            /* Determine slipping/falling state. */
            entity->setFalling(false);
            entity->setSlipping(false);
            Vector2D down = gravity;
            down.setLength(VERY_CLOSE * 100.0f);
            if(collisionDetector->getClosestCollision(entity->getRadius(),
                    position, down, &time, &collision)) {
                Vector2D fall = collision - position;
                float cosine = (gravity * fall) /
                        (gravity.getLength() * fall.getLength());
                if(cosine < 1.0f - SLIP_LIMIT || cosine > 1.0f + SLIP_LIMIT)
                    entity->setSlipping(true);
            } else {
                entity->setFalling(true);
            }

            if(entity->isFalling() || entity->isSlipping())
                velocity += gravity * ms;

            /* Now set the entity's state. */
            entity->setPosition(position);
            entity->setVelocity(velocity);
        }

        const Vector2D &CollisionResponsePositioner::getGravity() const
        {
            return gravity;
        }

        void CollisionResponsePositioner::setGravity(const Vector2D &gravity)
        {
            this->gravity = gravity;
        }
    }
}
