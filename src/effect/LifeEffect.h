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
                /** Initial life. */
                float initialLife;

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

                /** Get the inital lifetime given.
                 *  @return The initial lifetime.
                 */
                virtual float getInitialLife() const;

                /** Get the life left.
                 *  @return The life left.
                 */
                virtual float getLife() const;

                /** Get the life left divided by the initial lifetime.
                 *  @return The life fraction.
                 */
                virtual float getLifeFraction() const;

                /** Check if this effect has an infinite lifetime.
                 *  @return If this life has an infinite lifetime.
                 */
                virtual bool isImmortal() const;
        };
    }
}

#endif
