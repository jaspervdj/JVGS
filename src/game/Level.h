#ifndef JVGS_GAME_LEVEL_H
#define JVGS_GAME_LEVEL_H

#include "../sketch/Sketch.h"
#include "../video/Renderer.h"
#include <vector>
#include <string>
#include <map>

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Entity;

        /** Class that represents a level the player can play through.
         */
        class Level
        {
            private:
                /** The game world. */
                sketch::Sketch *world;

                /** The entities in the game world. */
                std::vector<Entity*> entities;

                /** Entities by id. */
                std::map<std::string, Entity*> entitiesById;

            public:
                /** Constructor.
                 */
                Level();

                /** Constructor.
                 *  @param element TiXmlElement to load the data from.
                 */
                Level(TiXmlElement *element);

                /** Detructor.
                 */
                virtual ~Level();

                /** Get the level world.
                 *  @return The level world.
                 */
                virtual sketch::Sketch *getWorld() const;

                /** Add an entity to the level.
                 *  @param entity Entity to add.
                 */
                virtual void addEntity(Entity *entity);

                /** Get an entity by id.
                 *  @param id Id of the entity to retrieve.
                 *  @return The requested entity.
                 */
                virtual Entity *getEntityById(const std::string &id);

                /** Update the level and everything in it.
                 *  @param ms Milliseconds to update for.
                 */
                virtual void update(float ms);

                /** Render the level to the screen.
                 */
                virtual void render();
        };
    }
}

#endif
