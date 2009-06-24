#include "Noise.h"
#include "MathManager.h"

#include <cmath>
#include <iostream>
using namespace std;

namespace jvgs
{
    namespace math
    {
        Noise::Noise(float min, float max, int waveLength)
        {
            this->min = min;
            this->max = max;
            this->waveLength = waveLength;

            current = MathManager::getInstance()->randFloat(min, max);
            next = MathManager::getInstance()->randFloat(min, max);

            position = 0;
        }

        Noise::~Noise()
        {
        }

        float Noise::nextValue()
        {
            float t = (float) position / (float) waveLength;

            float value = ((current + next) + (current - next) *
                    (float) cos(M_PI * t)) * 0.5f; 

            position++;
            if(position >= waveLength) {
                position = 0;
                current = next;
                next = MathManager::getInstance()->randFloat(min, max);
            }

            return value;
        }
    }
}
