#ifndef JVGS_MATH_MATHMANAGER_H
#define JVGS_MATH_MATHMANAGER_H

#ifndef M_PI
#define M_PI 3.14159265
#endif

namespace jvgs
{
    namespace math
    {
        /** Class to solve basic math problems.
         */
        class MathManager
        {
            protected:
                /** Constructor.
                 */
                MathManager();

                /** Destructor.
                 */
                ~MathManager();

            public:
                /** Obtain the MathManager instance.
                 *  @return The MathManager instance.
                 */
                static MathManager *getInstance();

                /** Returns the next power of two.
                 *  \param input Any positive integer.
                 *  \return A power of two, larger than input.
                 */
                int nearestPowerOfTwo(const int &input) const;

                /** Creates a new random seed.
                 */
                void newRandomSeed() const;

                /** Get a random integer.
                 *  \param maximum The maximum, exclusive.
                 *  \return The random integer.
                 */
                int randInt(const int &maximum) const;

                /** Get a random integer.
                 *  \param minimum The minimum, inclusive.
                 *  \param maximum The maximum, exclusive.
                 *  \return The random integer.
                 */
                int randInt(const int &minimum, const int &maximum) const;

                /** Get a random floating point number between 0 and 1,
                 *  both inclusive.
                 *  \return A floating point number.
                 */
                float randFloat() const;

                /** Get a random floating point number between 0 and maximum.
                 *  \param maximum The maximum, inclusive.
                 */
                float randFloat(const float &maximum) const;

                /** Get a random floating point number.
                 *  \param minimum The minimum, inclusive.
                 *  \param maximum The maximum, inclusice.
                 *  \return A floating point number.
                 */
                float randFloat(const float &minimum, const float &maximum)
                    const;

                /** Get a random bool.
                 *  @param chance Chance on true (between 0.0 and 1.0).
                 */
                bool randBool(const float &chance = 0.5f) const;

                /** Returns a or b, whichever is the smallest.
                 *  \param a An integer.
                 *  \param b An integer.
                 *  \return The smallest of a and b.
                 */
                template <class T>
                const T &min(const T &a, const T &b) const
                {
                    return a < b ? a : b;
                }

                /** Returns a or b, whichever is the largest.
                 *  \param a An integer.
                 *  \param b An integer.
                 *  \return The largest of a and b.
                 */
                template <class T>
                const T &max(const T &a, const T &b) const
                {
                    return a > b ? a : b;
                }

                /** Returns the absolute value.
                 *  \param value An integer.
                 *  \return The absolute value of the input.
                 */
                template <class T>
                T abs(const T &value) const
                {
                    return value >= (T) 0 ? value : -value;
                }

                /** Returns the lowest positive root for a quadratic equation in
                 *  the form of a * x^2 + b * x + c = 0.
                 *  @param a A equation parameter.
                 *  @param b B equation parameter.
                 *  @param c C equation parameter.
                 *  @param treshold The lowest root must be <= this treshold.
                 *  @param root This will contain the root.
                 *  @return If a solution was found.
                 */
                bool getLowestPositiveRoot(float a, float b, float c,
                        float treshold, float *root) const;

                /** Clamp a to [lower, upper].
                 *  @param a Value to clamp.
                 *  @param lower Lower clamp boundary.
                 *  @param upper Upper clamp boundary.
                 *  @return Clamped value.
                 */
                float clamp(float a, float lower, float upper) const;

                /** Convert an angle in degrees to radians.
                 *  @param degrees Angle to convert.
                 *  @return The result in radians.
                 */
                float toRadians(float degrees) const;
        };
    };
};

#endif
