#ifndef JVGS_GAME_LEVEL_H
#define JVGS_GAME_LEVEL_H

#include "../sketch/Sketch.h"
#include "../video/Renderer.h"
#include "../core/XMLLoadable.h"
#include "../core/View.h"
#include "../math/BoundingBox.h"
#include <vector>
#include <string>
#include <map>

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Entity;
        class Camera;
        class CameraFactory;

        /** Class that represents a level the player can play through.
         */
        class Level: public core::XMLLoadable, public core::View
        {
            private:
                /** The game world. */
                sketch::Sketch *world;

                /** The entities in the game world. */
                std::vector<Entity*> entities;

                /** Entities by id. */
                std::map<std::string, Entity*> entitiesById;

                /** Camera. */
                Camera *camera;

                /** Level bounding box. */
                math::BoundingBox boundingBox;

                /** Camera factories. */
                static std::map<std::string, CameraFactory*> cameraFactories;

            protected:
                /* Override.
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 */
                Level();

                /** Constructor.
                 *  @param element TiXmlElement to load the data from.
                 */
                Level(TiXmlElement *element);

                /** Constructor.
                 *  @param fileName XML file to load the data from.
                 */
                Level(const std::string &fileName);

                /** Detructor.
                 */
                virtual ~Level();

                /** Get the level world.
                 *  @return The level world.
                 */
                virtual sketch::Sketch *getWorld() const;

                /** Get the number of entities.
                 *  @return The number of entities.
                 */
                virtual int getNumberOfEntities() const;

                /** Get an entity by index.
                 *  @param index Index of the entity to retrieve.
                 *  @return The requested entity.
                 */
                virtual Entity *getEntity(int index) const;

                /** Add an entity to the level.
                 *  @param entity Entity to add.
                 */
#               ifdef SWIG
                    %apply SWIGTYPE *DISOWN {Entity* entity};
#               endif
                virtual void addEntity(Entity *entity);

                /** Get an entity by id.
                 *  @param id Id of the entity to retrieve.
                 *  @return The requested entity.
                 */
                virtual Entity *getEntityById(const std::string &id);

                /* Override
                 */
                virtual void update(float ms);

                /* Override
                 */
                virtual void render();
        };
    }
}

#endif
