#ifndef JVGS_MATH_MATHMANAGER_H
#define JVGS_MATH_MATHMANAGER_H

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

                /** Returns a or b, whichever is the smallest.
                 *  \param a An integer.
                 *  \param b An integer.
                 *  \return The smallest of a and b.
                 */
                int min(const int &a, const int &b) const;

                /** Returns a or b, whichever is the largest.
                 *  \param a An integer.
                 *  \param b An integer.
                 *  \return The largest of a and b.
                 */
                int max(const int &a, const int &b) const;

                /** Returns the absolute value.
                 *  \param value An integer.
                 *  \return The absolute value of the input.
                 */
                int abs(const int &value) const;

                /** Returns the absolute value.
                 *  \param value A floating point number.
                 *  \return The absolute value of the input.
                 */
                float abs(const float &value) const;

                /** Returns the lowest positive root for a quadratic equation in
                 *  the form of a * x^2 + b * x + c = 0.
                 *  @param a A equation parameter.
                 *  @param b B equation parameter.
                 *  @param c C equation parameter.
                 *  @param treshold The lowest root must be below this treshold.
                 *  @param root This will contain the root.
                 *  @return If a solution was found.
                 */
                bool getLowestPositiveRoot(float a, float b, float c,
                        float treshold, float *root) const;
        };
    };
};

#endif
