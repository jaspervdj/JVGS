#include "Renderer.h"
#include "VideoManager.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/MathManager.h"
using namespace jvgs::math;

#include <iostream>
#include <cmath>
using namespace std;

namespace jvgs
{
    namespace video
    {
        Renderer::Renderer()
        {
            busy = false;
            noiseX = new Noise(-2.0f, 2.0f, 5);
            noiseY = new Noise(-2.0f, 2.0f, 5);
        }

        Renderer::~Renderer()
        {
            delete noiseX;
            delete noiseY;
        }

        void Renderer::begin(Type type)
        {
            busy = true;
            rendering = type;
            vectorList.clear();
        }

        void Renderer::end()
        {
            busy = false;

            int repeat = MathManager::getInstance()->randInt(1, 10);
            int start = 0, end = vectorList.size();
            while(repeat > 0) {
                glBegin(GL_LINE_STRIP);
                
                for(int i = start; i < end; i++) {
                    Vector2D vector2d = vectorList[i];
                    glVertex2f(vector2d.getX() + noiseX->nextValue(),
                            vector2d.getY() + noiseY->nextValue());
                }

                glEnd();

                start = MathManager::getInstance()->randInt(0,
                        vectorList.size());
                end = MathManager::getInstance()->randInt(0,
                        vectorList.size());

                if(start > end) {
                    int tmp = end;
                    end = start;
                    start = tmp;
                }

                repeat--;
            }

            vectorList.clear();
        }

        bool Renderer::isBusy() const
        {
            return busy;
        }

        void Renderer::vector(const Vector2D &vector)
        {
            /* Regular. */
            vectorList.push_back(vector);
        }
    };
};
