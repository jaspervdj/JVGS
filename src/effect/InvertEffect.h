#ifndef JVGS_EFFECT_INVERTEFFECT_H
#define JVGS_EFFECT_INVERTEFFECT_H

#include "LifeEffect.h"

namespace jvgs
{
    namespace effect
    {
        class InvertEffect: public LifeEffect
        {
            public:
                /** Constructor.
                 *  @param life Lifetime in milliseconds.
                 */
                InvertEffect(float life = 5000);

                /** Destructor.
                 */
                virtual ~InvertEffect();

                /** Override
                 */
                virtual void update(float ms);

                /** Override
                 */
                virtual void render();
        };
    }
}

#endif
