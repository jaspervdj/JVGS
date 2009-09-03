#include "SketchyRenderer.h"

#include "../math/MathManager.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace video
    {
        SketchyRenderer::SketchyRenderer()
        {
            noiseX = new Noise(-2.0f, 2.0f, 5);
            noiseY = new Noise(-2.0f, 2.0f, 5);
        }

        SketchyRenderer::~SketchyRenderer()
        {
            delete noiseX;
            delete noiseY;
        }

        void SketchyRenderer::begin(RenderType type)
        {
            Renderer::begin(type);
            vectorList.clear();
            noiseX->seed();
            noiseY->seed();
        }

        void SketchyRenderer::end()
        {
            Renderer::end();

            int repeat = MathManager::getInstance()->randInt(1, 10);
            int start = 0, end = (int) vectorList.size();
            while(repeat > 0) {
                glBegin(GL_LINE_STRIP);
                
                for(int i = start; i < end; i++) {
                    Vector2D vector2d = vectorList[i];
                    glVertex2f(vector2d.getX() + noiseX->nextValue(),
                            vector2d.getY() + noiseY->nextValue());
                }

                glEnd();

                start = MathManager::getInstance()->randInt(0,
                        (int) vectorList.size());
                end = MathManager::getInstance()->randInt(0,
                        (int) vectorList.size());

                if(start > end) {
                    int tmp = end;
                    end = start;
                    start = tmp;
                }

                repeat--;
            }

            vectorList.clear();
        }

        void SketchyRenderer::vector(const Vector2D &vector)
        {
            vectorList.push_back(vector);
        }
    };
};
