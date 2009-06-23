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
                Noise(float min, float max, int waveLength);
                virtual ~Noise();

                float nextValue();
        };
    }
}

#endif
