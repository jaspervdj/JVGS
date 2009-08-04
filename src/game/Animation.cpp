#include "Animation.h"

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

using namespace std;

namespace jvgs
{
    namespace game
    {
        struct AnimationFrame
        {
            Sketch *sketch;
            float duration;
        };

        Animation::Animation()
        {
            currentFrame = 0;
            counter = 0;
        }

        Animation::~Animation()
        {
            /* Clear AnimationFrames. */
            for(vector<AnimationFrame*>::iterator iterator = frames.begin();
                    iterator != frames.end(); iterator++)
                delete (*iterator);
        }

        void Animation::update(float ms)
        {
            if(frames.size() > 0) {
                counter += ms;
                while(counter >= frames[currentFrame]->duration) {
                    counter -= frames[currentFrame]->duration;
                    currentFrame = (currentFrame + 1) % frames.size();
                }
            }
        }

        void Animation::render()
        {
            if(frames.size() > 0)
                frames[currentFrame]->sketch->render();
        }
    }
}
