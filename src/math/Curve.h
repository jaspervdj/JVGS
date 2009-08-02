#ifndef JVGS_MATH_CURVE_H
#define JVGS_MATH_CURVE_H

#include "PathSegment.h"

namespace jvgs
{
    namespace math
    {
        class Curve: public PathSegment
        {
            private:
                /** Calculated length. */
                float length;

            public:
                /** Constructor.
                 */
                Curve();

                /** Destructor.
                 */
                virtual ~Curve();

                /* Override.
                 */
                virtual float getLength() const;

            protected:
                /** Calculate the actual length.
                 */
                virtual void calculateLength();

                /** Get a simple guess at the length. This is used in the
                 *  approximation algorithm. It would be ideal if this result
                 *  would be larger than the actual length, but too large or
                 *  the calculation will be slower.
                 *  @return A guess at the length.
                 */
                virtual float getLengthGuess() const = 0;
        };
    }
}

#endif
