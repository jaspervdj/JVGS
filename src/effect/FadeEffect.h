#ifndef JVGS_EFFECT_FADEEFFECT_H
#define JVGS_EFFECT_FADEEFFECT_H

#include "LifeEffect.h"
#include "../video/Color.h"

namespace jvgs
{
    namespace effect
    {
        class FadeEffect: public LifeEffect
        {
            private:
                /** Original foreground color.
                 */
                video::Color color;

            public:
                /** Constructor.
                 *  @param life Lifetime in milliseconds.
                 */
                FadeEffect(float life = 5000);

                /** Destructor.
                 */
                virtual ~FadeEffect();

                /** Override
                 */
                virtual void render();
        };
    }
}

#endif
