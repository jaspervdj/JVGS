#include "Curve.h"

namespace jvgs
{
    namespace math
    {
        Curve::Curve()
        {
            length = 0.0f;
        }

        Curve::~Curve()
        {
        }

        float Curve::getLength() const
        {
            return length;
        }

        void Curve::calculateLength()
        {
            /* Calculate length. First, take a simple guess. The real length
             * will probably be smaller. */
            float simpleGuess = getLengthGuess();
            float increment = 1.0f / simpleGuess;

            /* Now approximate the real length. */
            length = 0.0f;

            /* getPoint(0.0f) equals start, so... */
            Vector2D previous = getPoint(0.0f), current; 
            for(float t = increment; t <= 1.0f; t += increment) {
                current = getPoint(t);
                length += previous.getDistance(current);
                previous = current;
            }
        }
    }
}
