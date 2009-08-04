#ifndef JVGS_GAME_ANIMATION_H
#define JVGS_GAME_ANIMATION_H

#include <vector>

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
                /** The frames of the animation. */
                std::vector<AnimationFrame*> frames;

                /** The current frame. */
                std::vector<AnimationFrame*>::size_type currentFrame;

                /** Counter keeping the current time. */
                float counter;

            public:
                /** Constructor. Create an empty animation.
                 */
                Animation();

                /** Destructor.
                 */
                virtual ~Animation();

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
