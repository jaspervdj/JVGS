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

#include <iostream>
using namespace std;

namespace jvgs
{
    namespace game
    {
        const float CollisionResponsePositioner::VERY_CLOSE = 0.1f;
        const int CollisionResponsePositioner::MAX_STEPS = 10;
        const float CollisionResponsePositioner::SLIP_LIMIT = 0.1f;

        void CollisionResponsePositioner::loadData(TiXmlElement *element)
        {
            Positioner::loadData(element);
            element->QueryFloatAttribute("jumpdistancelimit",
                    &jumpDistanceLimit);
        }

        CollisionResponsePositioner::CollisionResponsePositioner(Entity *entity)
                : Positioner(entity)
        {
            setGravity(Vector2D(0.0f, 0.0f));
            jumpDistanceLimit = 100.0f;
        }

        CollisionResponsePositioner::CollisionResponsePositioner(Entity *entity,
                TiXmlElement *element): Positioner(entity)
        {
            setGravity(Vector2D(0.0f, 0.0f));
            jumpDistanceLimit = 100.0f;
            load(element);
        }

        CollisionResponsePositioner::~CollisionResponsePositioner()
        {
        }

        void CollisionResponsePositioner::affect(float ms)
        {
            Entity *entity = getEntity();
            CollisionDetector *collisionDetector =
                    entity->getLevel()->getCollisionDetector();

            /* Store the original ms. */
            float timeLeft = 1.0f;

            /* Get vectors. */
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

                    /* Stuck. */
                    if(time <= 0.0f) {
                        std::cout << "Stuck!" << endl;
                        Vector2D correction = -getGravity();
                        correction.setLength(VERY_CLOSE);
                        newPosition = position + correction;
                    } else {
                        /* Only update above a certain distance. */
                        float distance = (velocity * time).getLength();
                        if(distance >= VERY_CLOSE) {
                            Vector2D v = velocity;
                            v.setLength(distance - VERY_CLOSE);
                            newPosition = position + v;
                        }
                    }

                    /* Subtract used velocity. */
                    velocity *= (1.0f - time);

                    /* Add a normal force. */
                    Vector2D normalForce = position - collision;
                    normalForce.setLength(velocity.getLength());
                    velocity += normalForce;

                    /* A little bit of damping. */
                    velocity /= 2.0f;
 
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
            Vector2D down = getGravity();
            down.setLength(VERY_CLOSE * 20.0f);
            if(collisionDetector->getClosestCollision(entity->getRadius(),
                    position, down, &time, &collision)) {
                Vector2D fall = collision - position;
                float cosine = (getGravity() * fall) /
                        (getGravity().getLength() * fall.getLength());
                if(cosine < 1.0f - SLIP_LIMIT || cosine > 1.0f + SLIP_LIMIT)
                    entity->setSlipping(true);
            } else {
                entity->setFalling(true);
            }

            if(entity->isFalling() || entity->isSlipping())
                velocity += getGravity() * ms;

            /* Now set the entity's state. */
            entity->setPosition(position);
            entity->setVelocity(velocity);
        }

        bool CollisionResponsePositioner::canJump()
        {
            Entity *entity = getEntity();
            CollisionDetector *collisionDetector =
                    entity->getLevel()->getCollisionDetector();
            Vector2D down = getGravity();
            float time;
            Vector2D collision;

            down.setLength(jumpDistanceLimit);
            return collisionDetector->getClosestCollision(entity->getRadius(),
                    entity->getPosition(), down, &time, &collision);
        }
    }
}
