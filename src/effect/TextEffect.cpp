#include "TextEffect.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../font/FontManager.h"
using namespace jvgs::font;

using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace effect
    {
        TextEffect::TextEffect(const string &text, const Vector2D &position,
                float life)
        {
            this->text = text;
            this->position = position;
            this->life = life;

            FontManager *fontManager = FontManager::getInstance();
            font = fontManager->getFont("effect");
            if(!font)
                font = fontManager->getFont("regular");

            width = font->getStringWidth(text);
        }

        TextEffect::~TextEffect()
        {
        }

        void TextEffect::update(float ms)
        {
            life -= ms;
            if(life <= 0.0f)
                setGarbage();
        }

        void TextEffect::render()
        {
            VideoManager *videoManager = VideoManager::getInstance();
            videoManager->push();
            videoManager->translate(position - Vector2D(width, 0.0f) * 0.5f);
            font->drawString(text);
            videoManager->pop();
        }
    }
}
