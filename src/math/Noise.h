#ifndef JVGS_MATH_NOISE_H
#define JVGS_MATH_NOISE_H

namespace jvgs
{
    namespace math
    {
        /** A noise is a random number source with random
         *  numbers generate a smooth noise.
         */
        class Noise
        {
            private:
                /** Min and max values. */
                float min, max;

                /** Wavelength. */
                int waveLength;

                /** Current and next wave value. */
                float current, next;

                /** Position relative to previous wave extrema. */
                int position;
            public:
                /** Constructor.
                 *  @param min Minimum noise value.
                 *  @param max Maximum noise value.
                 *  @param waveLength The wavelength of the noise.
                 */
                Noise(float min, float max, int waveLength);
                virtual ~Noise();

                /** Resets the noise to a new random state, independent
                 *  of the previous state.
                 */
                void seed();

                /** Get the next value from the noise.
                 *  @return The next noise value.
                 */
                float nextValue();
        };
    }
}

#endif
