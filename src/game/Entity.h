#ifndef JVGS_GAME_ENTITY_H
#define JVGS_GAME_ENTITY_H

#include "../math/BoundingBox.h"
#include "../math/BoundedObject.h"
#include "../math/Vector2D.h"
#include "AffectorFactory.h"
#include "../core/XMLLoadable.h"
#include "../core/PropertyMap.h"
#include <string>
#include <map>

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Controller;
        class Positioner;
        class Sprite;
        class Level;

        class Entity: public math::BoundedObject, public core::PropertyMap
        {
            private:
                /** Entity id. */
                std::string id;

                /** Level the entity is in. */
                Level *level;

                /** The entity position. */
                math::Vector2D position;

                /** The entity velocity. */
                math::Vector2D velocity;

                /** Radius used for collision detection. */
                math::Vector2D radius;

                /** If the entity actively checks for collision with other
                 *  entities. */
                bool collisionChecker;

                /** If the entity is garbage and should be removed. */
                bool garbage;

                /** Speed of the entity. */
                float speed;

                /** If the entity is falling. */
                bool falling;

                /** If the entity is slipping. */
                bool slipping;

                /** Entity controller. */
                Controller *controller;

                /** Entity positioner. */
                Positioner *positioner;

                /** Entity sprite. */
                Sprite *sprite;

                /** Used for sprite selection. */
                bool facingRight;

                /** Event script. */
                std::string script;

                /** Bounding box. */
                math::BoundingBox boundingBox;

                /** Map for controller factories. */
                static std::map<std::string, AffectorFactory<Controller>*> 
                        controllerFactories;

                /** Map for positioner factories. */
                static std::map<std::string, AffectorFactory<Positioner>*>
                        positionerFactories;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param id Id for the entity.
                 *  @param collisionChecker Check for collisions actively?
                 *  @param level Level the entity is in.
                 */
                Entity(const std::string &id, bool collisionChecker,
                        Level *level);

                /** Constructor.
                 *  @param element TiXmlElement to load entity from.
                 *  @param level Level the entity is in.
                 */
                Entity(TiXmlElement *element, Level *level);

                /** Destructor.
                 */
                virtual ~Entity();

                /** Get the entity id.
                 *  @return The id for this entity.
                 */
                virtual const std::string &getId() const;

                /** Get the entity level.
                 *  @return The level the entity is in.
                 */
                virtual Level *getLevel() const;

                /** Get the entity position.
                 *  @return The entity position.
                 */
                virtual const math::Vector2D &getPosition() const;

                /** Set the entity position.
                 *  @param position The new entity position.
                 */
                virtual void setPosition(const math::Vector2D &position);

                /** Get the entity velocity.
                 *  @return The entity velocity.
                 */
                virtual const math::Vector2D &getVelocity() const;

                /** Set the entity velocity.
                 *  @param velocity The new entity velocity.
                 */
                virtual void setVelocity(const math::Vector2D &velocity);

                /** Get the radius used for collision detection.
                 *  @return The radius used for collision detection.
                 */
                virtual const math::Vector2D &getRadius() const;

                /** Set the radius used for collision detection.
                 *  @param radius The new radius.
                 */
                virtual void setRadius(const math::Vector2D &radius);

                /** See if this object actively checks for collisions.
                 *  @return If this object actively checks for collisions.
                 */
                virtual bool isCollisionChecker() const;

                /** See if this object is garbage. When garbage, it should be
                 *  removed.
                 *  @return If this entity is garbage.
                 */
                virtual bool isGarbage() const;

                /** Mark this entity as being garbage. It will be removed later.
                 */
                virtual void setGarbage();

                /** Get the speed for this entity.
                 *  @return The speed for this entity.
                 */
                virtual float getSpeed() const;

                /** Set the speed for this entity.
                 *  @param speed The new speed for this entity.
                 */
                virtual void setSpeed(float speed);

                /** Check if the entity is falling.
                 *  @return If the entity is falling.
                 */
                virtual bool isFalling() const;

                /** Set the falling state.
                 *  @param falling If the entity is falling.
                 */
                virtual void setFalling(bool falling);

                /** Check if the entity is slipping.
                 *  @return If the entity is slipping.
                 */
                virtual bool isSlipping() const;

                /** Set the slipping state.
                 *  @param slipping If the entity is slipping.
                 */
                virtual void setSlipping(bool slipping);

                /** Set the controller of this entity.
                 *  @param controller The controller of this entity.
                 */
#               ifdef SWIG
                    %apply SWIGTYPE *DISOWN {Controller* controller};
#               endif
                virtual void setController(Controller *controller);

                /** Get the controller of this entity.
                 *  @return The controller of this entity.
                 */
                virtual Controller *getController() const;

                /** Set the positioner of this entity.
                 *  @param positioner The positioner of this entity.
                 */
#               ifdef SWIG
                    %apply SWIGTYPE *DISOWN {Positioner* positioner};
#               endif
                virtual void setPositioner(Positioner *positioner);

                /** Get the positioner of this entity.
                 *  @return The positioner of this entity.
                 */
                virtual Positioner *getPositioner() const;

                /** Set the sprite of this entity.
                 *  @param sprite The sprite of this entity.
                 */
#               ifdef SWIG
                    %apply SWIGTYPE *DISOWN {Sprite* sprite};
#               endif
                virtual void setSprite(Sprite *sprite);

                /** Get the sprite of this entity.
                 *  @return The sprite of this entity.
                 */
                virtual Sprite *getSprite() const;

                /** Set the event script.
                 *  @param script The event script.
                 */
                virtual void setScript(const std::string &script);

                /** Get the event script.
                 *  @return The event script.
                 */
                virtual const std::string &getScript() const;

                /** Get a bounding box for the entity.
                 *  @return A bounding box for the entity.
                 */
                virtual math::BoundingBox *getBoundingBox();

                /** Update this entity for a given time.
                 *  @param ms Time to update for.
                 */
                virtual void update(float ms);

                /** Render this entity to the screen.
                 */
                virtual void render();
        };
    }
}

#endif
