#include "Animation.h"

#include "../sketch/Sketch.h"
#include "../sketch/SketchManager.h"
using namespace jvgs::sketch;

#include "../tinyxml/tinyxml.h"

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

        Animation::Animation(TiXmlElement *element)
        {
            /* Loop through all frame elements, adding them. */
            TiXmlElement *child = element->FirstChildElement("frame");
            while(child) {
                string fileName = child->Attribute("sketch");
                float duration;
                child->QueryFloatAttribute("duration", &duration);
                addFrame(fileName, duration);
                child = child->NextSiblingElement("frame");
            }
        }

        Animation::~Animation()
        {
            /* Clear AnimationFrames. */
            for(vector<AnimationFrame*>::iterator iterator = frames.begin();
                    iterator != frames.end(); iterator++)
                delete (*iterator);
        }

        void Animation::addFrame(const string &fileName, float duration)
        {
            SketchManager *sketchManager = SketchManager::getInstance();
            AnimationFrame *frame = new AnimationFrame;
            frame->sketch = sketchManager->getSketch(fileName);
            frame->duration = duration;
            frames.push_back(frame);
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
