#ifndef JVGS_EFFECT_PARTICLE_H
#define JVGS_EFFECT_PARTICLE_H

#include "../sketch/Sketch.h"
#include "LifeEffect.h"
#include "../math/Vector2D.h"

namespace jvgs
{
    namespace effect
    {
        /** Particle used with particle effects.
         */
        class Particle: public LifeEffect
        {
            private:
                /** Sketch used. */
                sketch::Sketch *sketch;

                /** Position. */
                math::Vector2D position;

                /** Velocity. */
                math::Vector2D velocity;

                /** Gravity. */
                math::Vector2D gravity;

            public:
                /** Constructor.
                 *  @param sketch Sketch to draw for the particle. Not deleted.
                 *  @param life Lifetime given to particle.
                 *  @param position Initial position of the particle.
                 *  @param velocity Initial velocity of the particle.
                 *  @param gravity Gracity pulling the particle.
                 */
                Particle(sketch::Sketch *sketch, float life,
                        const math::Vector2D &position,
                        const math::Vector2D &velocity,
                        const math::Vector2D &gravity);

                /** Destructor.
                 */
                virtual ~Particle();

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
