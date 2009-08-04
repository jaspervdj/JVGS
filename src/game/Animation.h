#ifndef JVGS_GAME_ANIMATION_H
#define JVGS_GAME_ANIMATION_H

#include <vector>
#include <string>

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        /** Internally used.
         */
        struct AnimationFrame;

        /** An animation is a number of sprites.
         */
        class Animation
        {
            private:
                /** Id of the animation. */
                std::string id;

                /** The frames of the animation. */
                std::vector<AnimationFrame*> frames;

                /** The current frame. */
                std::vector<AnimationFrame*>::size_type currentFrame;

                /** Counter keeping the current time. */
                float counter;

            public:
                /** Constructor. Create an empty animation.
                 *  @param id Id for the animation.
                 */
                Animation(const std::string &id);

                /** Constructor. Create an animation from the data in the
                 *  element.
                 *  @param element XML element containing animation data.
                 */
                Animation(TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~Animation();

                /** Get the animation id.
                 *  @return The animation id.
                 */
                virtual const std::string &getId() const;

                /** Add a frame with a given sketch and duration.
                 *  @param fileName File name of the frame.
                 *  @param duration Duration of the frame.
                 */
                virtual void addFrame(const std::string &fileName,
                        float duration);

                /** Update the animation.
                 *  @param ms Milliseconds to update for.
                 */
                virtual void update(float ms);

                /** Render the animation to the screen.
                 */
                virtual void render();
        };
    }
}

#endif
