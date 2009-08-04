#include "Sprite.h"
#include "Animation.h"

#include "../tinyxml/tinyxml.h"

using namespace std;

namespace jvgs
{
    namespace game
    {
        Sprite::Sprite()
        {
            current = "none";
        }

        Sprite::Sprite(TiXmlElement *element)
        {
            /* Loop through all animation elements, adding them. */
            TiXmlElement *child = element->FirstChildElement("animation");
            while(child) {
                Animation *animation = new Animation(child);
                addAnimation(animation);
                child = child->NextSiblingElement("frame");
            }
        }


        Sprite::~Sprite()
        {
            /* Clear all animations. */
            for(map<string, Animation*>::iterator iterator =
                    animations.begin(); iterator != animations.end();
                    iterator++) {
                delete iterator->second;
            }
        }

        void Sprite::addAnimation(Animation *animation)
        {
            animations[animation->getId()] = animation;
        }

        void Sprite::setAnimation(const string &current)
        {
            map<string, Animation*>::iterator result =
                    animations.find(current);
            if(result != animations.end())
                this->current = current;
        }

        void Sprite::update(float ms)
        {
            animations[current]->update(ms);
        }

        void Sprite::render()
        {
            animations[current]->render();
        }
    }
}
