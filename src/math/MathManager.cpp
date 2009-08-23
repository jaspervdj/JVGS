#include "MathManager.h"

#include <cstdlib>
#include <ctime>
#include <cmath>

namespace jvgs
{
    namespace math
    {
        MathManager::MathManager()
        {
            newRandomSeed();
        }

        MathManager::~MathManager()
        {
        }

        MathManager *MathManager::getInstance()
        {
            static MathManager instance;
            return &instance;
        }

        int MathManager::nearestPowerOfTwo(const int &input) const
        {
            int value = 1;
            while(value<input)
                value <<= 1;
            return value;
        }

        void MathManager::newRandomSeed() const
        {
            srand((unsigned int) time(0));
        }

        int MathManager::randInt(const int &maximum) const
        {
            return rand()%maximum;
        }

        int MathManager::randInt(const int &minimum, const int &maximum) const
        {
            if(minimum == maximum)
                return minimum;
            else
                return minimum + rand()%(maximum-minimum);
        }

        float MathManager::randFloat() const
        {
            return rand()/((float)(RAND_MAX)+1.0f);
        }

        float MathManager::randFloat(const float &maximum) const
        {
            return randFloat() * maximum;
        }

        float MathManager::randFloat(const float &minimum,
                                     const float &maximum) const
        {
            return minimum + randFloat()*(maximum-minimum);
        }

        bool MathManager::randBool(const float &chance) const
        {
            return randFloat() < chance;
        }

        bool MathManager::getLowestPositiveRoot(float a, float b, float c,
                float treshold, float *root) const
        {
            /* Calculate determinant. */
            float d = b * b - 4.0f * a * c;

            /* No solution. */
            if(d < 0.0f)
                return false;

            /* Calculate the two roots. */
            float sqrtD = sqrt(d);
            float x1 = (-b - sqrtD) / (2.0f * a);
            float x2 = (-b + sqrtD) / (2.0f * a);

            /* Sort solutions. */
            if(x1 > x2) {
                float tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            
            /* x1 is a solution. */
            if(x1 >= 0 && x1 <= treshold) {
                *root = x1;
                return true;
            }

            /* When x1 < 0 */
            if(x2 >= 0 && x2 <= treshold) {
                *root = x2;
                return true;
            }
            
            /* No solution found. */
            return false;
        }

        float MathManager::clamp(float a, float lower, float upper) const
        {
            if(a < lower)
                return lower;
            if(a > upper)
                return upper;
            return a;
        }
    };
};
