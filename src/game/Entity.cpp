#include "Entity.h"
#include "Controller.h"
#include "Positioner.h"
#include "Sprite.h"
#include "InputController.h"
#include "CollisionResponsePositioner.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../tinyxml/tinyxml.h"

using namespace std;
using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        Entity::Entity(const std::string &id, Level *level)
        {
            this->id = id;
            this->level = level;
            position = Vector2D(0.0f, 0.0f);
            velocity = Vector2D(0.0f, 0.0f);
            radius = Vector2D(0.0f, 0.0f);
            speed = 0.3f;
            falling = true;
            slipping = false;
            controller = 0;
            positioner = 0;
            sprite = 0;
            facingRight = true;
        }

        Entity::Entity(TiXmlElement *element, Level *level)
        {
            /* Load basic data. */
            id = element->Attribute("id");
            this->level = level;
            position = Vector2D(element->FirstChildElement("position"));
            velocity = Vector2D(element->FirstChildElement("velocity"));
            radius = Vector2D(element->FirstChildElement("radius"));
            element->QueryFloatAttribute("speed", &speed);

            /* Load controller. */
            TiXmlElement *controllerElement =
                    element->FirstChildElement("controller");
            if(!strcmp("InputController", controllerElement->Attribute("type")))
                controller = new InputController(this, controllerElement);

            /* Load positioner. */
            TiXmlElement *positionerElement =
                    element->FirstChildElement("positioner");
            if(!strcmp("CollisionResponsePositioner",
                    positionerElement->Attribute("type")))
                positioner = new CollisionResponsePositioner(this,
                        positionerElement);

            /* Load sprite. */
            TiXmlElement *spriteElement = element->FirstChildElement("sprite");
            sprite = spriteElement ? new Sprite(spriteElement) : 0;

            facingRight = true;
        }

        Entity::~Entity()
        {
            if(controller)
                delete controller;
            if(positioner)
                delete positioner;
            if(sprite)
                delete sprite;
        }

        const string &Entity::getId() const
        {
            return id;
        }

        Level *Entity::getLevel() const
        {
            return level;
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

        const Vector2D &Entity::getRadius() const
        {
            return radius;
        }

        void Entity::setRadius(const Vector2D &radius)
        {
            this->radius = radius;
        }

        float Entity::getSpeed() const
        {
            return speed;
        }

        void Entity::setSpeed(float speed)
        {
            this->speed = speed;
        }

        bool Entity::isFalling() const
        {
            return falling;
        }

        void Entity::setFalling(bool falling)
        {
            this->falling = falling;
        }

        bool Entity::isSlipping() const
        {
            return slipping;
        }

        void Entity::setSlipping(bool slipping)
        {
            this->slipping = slipping;
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

        void Entity::setSprite(Sprite *sprite)
        {
            if(this->sprite)
                delete this->sprite;
            this->sprite = sprite;
        }

        Sprite *Entity::getSprite() const
        {
            return sprite;
        }

        void Entity::update(float ms)
        {
            if(controller)
                controller->affect(ms);
            if(positioner)
                positioner->affect(ms);

            if(velocity.getX() <= -0.5f * speed && facingRight)
                facingRight = false;
            if(velocity.getX() >= 0.5f * speed && !facingRight)
                facingRight = true;

            if(falling || slipping)
                sprite->setAnimation("falling");
            else if(velocity.getLength() >= 0.2f * speed)
                sprite->setAnimation("walking");
            else
                sprite->setAnimation("standing");

            if(sprite)
                sprite->update(ms);
        }

        void Entity::render()
        {
            if(sprite) {
                VideoManager *videoManager = VideoManager::getInstance();

                videoManager->push();
                videoManager->translate(position);

                if(!facingRight)
                    videoManager->scale(Vector2D(-1.0f, 1.0f));

                videoManager->translate(-radius);

                sprite->render();

                videoManager->pop();
            }
        }
    }
}
