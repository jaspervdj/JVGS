#include "Entity.h"
#include "EntityEvent.h"
#include "Level.h"
#include "Controller.h"
#include "Positioner.h"
#include "Sprite.h"
#include "BullController.h"
#include "InputController.h"
#include "CollisionResponsePositioner.h"
#include "NaivePositioner.h"
#include "AffectorFactory.h"
#include "ControllerFactory.h"
#include "PositionerFactory.h"
#include "SillyController.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../bind/ScriptManager.h"
using namespace jvgs::bind;

#include "../tinyxml/tinyxml.h"

#include <iostream>
using namespace std;
using namespace jvgs::math;

namespace jvgs
{
    namespace game
    {
        /* Function to fill in the controller factories. */
        map<string, AffectorFactory<Controller>*> createControllerFactories()
        {
            map<string, AffectorFactory<Controller>*> controllerFactories;

            static ControllerFactory<BullController> bullControllerFactory;
            controllerFactories["BullController"] = &bullControllerFactory;

            static ControllerFactory<InputController> inputControllerFactory;
            controllerFactories["InputController"] = &inputControllerFactory;

            static ControllerFactory<SillyController> sillyControllerFactory;
            controllerFactories["SillyController"] = &sillyControllerFactory;

            return controllerFactories;
        }

        map<string, AffectorFactory<Controller>*> Entity::controllerFactories =
                createControllerFactories();

        /* Function to fill in the positioner factories. */
        map<string, AffectorFactory<Positioner>*> createPositionerFactories()
        {
            map<string, AffectorFactory<Positioner>*> positionerFactories;

            static PositionerFactory<CollisionResponsePositioner>
                    collisionResponsePositionerFactory;
            positionerFactories["CollisionResponsePositioner"] =
                    &collisionResponsePositionerFactory;

            static PositionerFactory<NaivePositioner> naivePositionerFactory;
            positionerFactories["NaivePositioner"] = &naivePositionerFactory;

            return positionerFactories;
        }

        map<string, AffectorFactory<Positioner>*> Entity::positionerFactories =
                createPositionerFactories();

        void Entity::loadData(TiXmlElement *element)
        {
            PropertyMap::loadData(element);

            /* Get id. */
            if(element->Attribute("id"))
                setId(element->Attribute("id"));

            /* Load basic data. */
            setPosition(Vector2D(element->FirstChildElement("position")));
            setVelocity(Vector2D(element->FirstChildElement("velocity")));
            radius = Vector2D(element->FirstChildElement("radius"));
            collisionChecker = getBoolAttribute(element, "collisionChecker");

            float speed;
            element->QueryFloatAttribute("speed", &speed);
            setSpeed(speed);

            /* Load controller. */
            TiXmlElement *controllerElement =
                    element->FirstChildElement("controller");
            string type = controllerElement->Attribute("type");
            map<string, AffectorFactory<Controller>*>::iterator
                    controllerFactory = controllerFactories.find(type);
            if(controllerFactory != controllerFactories.end())
                controller = controllerFactory->second->create(this,
                        controllerElement);
            else
                LogManager::getInstance()->error("No controller: %s",
                        type.c_str());

            /* Load positioner. */
            TiXmlElement *positionerElement =
                    element->FirstChildElement("positioner");
            type = positionerElement->Attribute("type");
            map<string, AffectorFactory<Positioner>*>::iterator
                    positionerFactory = positionerFactories.find(type);
            if(positionerFactory != positionerFactories.end())
                positioner = positionerFactory->second->create(this,
                        positionerElement);
            else
                LogManager::getInstance()->error("No positioner: %s",
                        type.c_str());

            /* Load sprite. */
            TiXmlElement *spriteElement = element->FirstChildElement("sprite");
            sprite = spriteElement ? new Sprite(spriteElement) : 0;

            /* Load script. */
            script = element->Attribute("script") ?
                    element->Attribute("script") : "none";
        }

        Entity::Entity(const std::string &id, bool collisionChecker,
                Level *level): AbstractEntity(id, level)
        {
            radius = Vector2D(0.0f, 0.0f);
            this->collisionChecker = collisionChecker;
            falling = true;
            slipping = false;
            controller = 0;
            positioner = 0;
            sprite = 0;
            facingRight = true;
        }

        Entity::Entity(TiXmlElement *element, Level *level)
                : AbstractEntity("none", level)
        {
            load(element);
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

        const Vector2D &Entity::getRadius() const
        {
            return radius;
        }

        void Entity::setRadius(const Vector2D &radius)
        {
            this->radius = radius;
        }

        bool Entity::isCollisionChecker() const
        {
            return collisionChecker;
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

        void Entity::setScript(const string &script)
        {
            this->script = script;
        }

        const string &Entity::getScript() const
        {
            return script;
        }

        BoundingBox *Entity::getBoundingBox()
        {
            boundingBox = BoundingBox(getPosition() - radius,
                    getPosition() + radius);
            return &boundingBox;
        }

        void Entity::update(float ms)
        {
            if(controller)
                controller->affect(ms);
            if(positioner)
                positioner->affect(ms);

            if(getVelocity().getX() <= -0.5f * getSpeed() && facingRight)
                facingRight = false;
            if(getVelocity().getX() >= 0.5f * getSpeed() && !facingRight)
                facingRight = true;

            if(falling || slipping)
                sprite->setAnimation("falling");
            else if(getVelocity().getLength() >= 0.2f * getSpeed())
                sprite->setAnimation("walking");
            else
                sprite->setAnimation("standing");

            if(sprite)
                sprite->update(ms);

            /* Check for collision. */
            if(collisionChecker) {
                BoundingBox *myBoundingBox = getBoundingBox();
                for(int i = 0; i < getLevel()->getNumberOfEntities(); i++) {
                    Entity *other = getLevel()->getEntity(i);
                    if(this != other) {
                        /* Collision found. */
                        if(myBoundingBox->intersectsWith(
                                other->getBoundingBox())) {
                            EntityEvent::collision(this, other);
                        }
                    }
                }
            }
        }

        void Entity::render()
        {
            if(sprite) {
                VideoManager *videoManager = VideoManager::getInstance();

                videoManager->push();
                videoManager->translate(getPosition());

                if(!facingRight)
                    videoManager->scale(Vector2D(-1.0f, 1.0f));

                videoManager->translate(-radius);

                sprite->render();

                videoManager->pop();
            }
        }
    }
}
