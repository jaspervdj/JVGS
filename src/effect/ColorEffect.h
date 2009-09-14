#ifndef JVGS_EFFECT_COLOREFFECT_H
#define JVGS_EFFECT_COLOREFFECT_H

#include "LifeEffect.h"
#include "../video/Color.h"

namespace jvgs
{
    namespace effect
    {
        /** An effect that changes the screen colors.
         */
        class ColorEffect: public LifeEffect
        {
            private:
                /** Original color. */
                video::Color originalColor;

                /** Original clear color. */
                video::Color originalClearColor;

            public:
                /** Constructor.
                 *  @param color The new foreground color.
                 *  @param clearColor The new background color.
                 *  @param life Lifetime in milliseconds.
                 */
                ColorEffect(const video::Color &color,
                        const video::Color &clearColor, float life = 2000);

                /** Destructor.
                 */
                virtual ~ColorEffect();

                /* Override
                 */
                virtual void render();
        };
    }
}

#endif
