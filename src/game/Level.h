#ifndef JVGS_GAME_LEVEL_H
#define JVGS_GAME_LEVEL_H

#include "../sketch/Sketch.h"
#include "../video/Renderer.h"
#include <vector>
#include <string>

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

            public:
                /** Constructor.
                 */
                Level();

                /** Constructor.
                 *  @param element TiXmlElement to load the data from.
                 */
                Level(TiXmlElement *element);

                /** Constructor
                 *  @param fileName XML file to load the data from.
                 */
                Level(const std::string &fileName);

                /** Detructor.
                 */
                virtual ~Level();

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
