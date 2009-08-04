#include "Animation.h"

#include "../sketch/Sketch.h"
#include "../sketch/SketchManager.h"
using namespace jvgs::sketch;

#include "../core/LogManager.h"
using namespace jvgs::core;

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

        Animation::Animation(const string &id)
        {
            this->id = id;
            currentFrame = 0;
            counter = 0;
        }

        Animation::Animation(TiXmlElement *element)
        {
            if(element->Attribute("id"))
                id = element->Attribute("id");
            else
                LogManager::getInstance()->error("Animations must have an id.");

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

        const string &Animation::getId() const
        {
            return id;
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
