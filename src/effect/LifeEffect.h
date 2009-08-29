#ifndef JVGS_EFFECT_LIFEEFFECT_H
#define JVGS_EFFECT_LIFEEFFECT_H

#include "../core/View.h"

namespace jvgs
{
    namespace effect
    {
        /** An effect with limited timespan. */
        class LifeEffect: public core::View
        {
            private:
                /** Life left. */
                float life;

            public:
                /** Constructor.
                 *  @param life Lifetime given. 0 means infinity.
                 */
                LifeEffect(float life);

                /** Destructor.
                 */
                virtual ~LifeEffect();

                /* Override
                 */
                virtual void update(float ms);
        };
    }
}

#endif
