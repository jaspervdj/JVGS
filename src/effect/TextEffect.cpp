#include "TextEffect.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../font/FontManager.h"
using namespace jvgs::font;

#include "../math/MathManager.h"
using namespace jvgs::math;

using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace effect
    {
        TextEffect::TextEffect(const string &text, const Vector2D &position,
                float life, float rotationSpeed)
        {
            this->text = text;
            this->position = position;
            this->life = life;

            MathManager *mathManager = MathManager::getInstance();
            this->rotationSpeed = mathManager->randBool() ?
                    rotationSpeed : -rotationSpeed;

            FontManager *fontManager = FontManager::getInstance();
            font = fontManager->getFont("effect");
            if(!font)
                font = fontManager->getFont("regular");

            width = font->getStringWidth(text);
            rotation = mathManager->randFloat(360.0f);
        }

        TextEffect::~TextEffect()
        {
        }

        void TextEffect::update(float ms)
        {
            life -= ms;
            if(life <= 0.0f)
                setGarbage();

            rotation += rotationSpeed * ms;
            if(rotation > 360.0f)
                rotation -= (int)(rotation / 360) * 360;
        }

        void TextEffect::render()
        {
            VideoManager *videoManager = VideoManager::getInstance();
            videoManager->push();
            videoManager->translate(position);
            videoManager->rotate(rotation);
            videoManager->translate(-Vector2D(width, 0.0f) * 0.5f);
            font->drawString(text);
            videoManager->pop();
        }
    }
}
