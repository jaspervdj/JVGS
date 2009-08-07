#ifndef JVGS_GAME_SPRITE_H
#define JVGS_GAME_SPRITE_H

#include <map>
#include <string>
#include "../core/XMLLoadable.h"

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Animation;

        /** A sprite is a collection of animations.
         */
        class Sprite: public core::XMLLoadable
        {
            private:
                /** The animations in this sprite. */
                std::map<std::string, Animation*> animations;

                /** The current animation. */
                std::string current;
                
            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor. Create an empty sprite.
                 */
                Sprite();

                /** Constructor. Load a sprite from XML data.
                 *  @param element The XML data.
                 */
                Sprite(TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~Sprite();

                /** Add an animation to the sprite.
                 *  @param animation Animation to add.
                 */
                virtual void addAnimation(Animation *animation);

                /** Set the current animation.
                 *  @param current Id of the new current animation.
                 */
                void setAnimation(const std::string &current);

                /** Update the sprite.
                 *  @param ms Milliseconds to update for.
                 */
                virtual void update(float ms);

                /** Render the sprite to the screen.
                 */
                virtual void render();
        };
    }
}

#endif
