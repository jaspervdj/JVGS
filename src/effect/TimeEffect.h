#ifndef JVGS_EFFECT_TIMEEFFECT_H
#define JVGS_EFFECT_TIMEEFFECT_H

#include "LifeEffect.h"

namespace jvgs
{
    namespace effect
    {
        /** A slowmotion or fast forward time effect.
         */
        class TimeEffect: public LifeEffect
        {
            private:
            public:
                /** Constructor.
                 *  @param timeFactor TimeFactor to apply during the effect.
                 *  @param life Lifetime in milliseconds.
                 */
                TimeEffect(float timeFactor, float life);

                /** Destructor.
                 */
                virtual ~TimeEffect();

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
