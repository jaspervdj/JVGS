#include "MathManager.h"

#include <cstdlib>
#include <ctime>

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
            srand(time(0));
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

        int MathManager::min(const int &a, const int &b) const
        {
            return a<b?a:b;
        }

        int MathManager::max(const int &a, const int &b) const
        {
            return a>b?a:b;
        }

        int MathManager::abs(const int &value) const
        {
            return value>0?value:-value;
        }

        float MathManager::abs(const float &value) const
        {
            return value>0?value:-value;
        }
    };
};
