#include "Color.h"

namespace jvgs
{
    namespace video
    {
        Color::Color(float red, float green, float blue, float alpha)
        {
            this->red = red;
            this->green = green;
            this->blue = blue;
            this->alpha = alpha;
        }

        Color::~Color()
        {
        }

        const Color &Color::operator=(const Color &other)
        {
            red = other.red;
            green = other.green;
            blue = other.blue;
            alpha = other.alpha;
            return *this;
        }

        float Color::getRed() const
        {
            return red;
        }

        void Color::setRed(float red)
        {
            this->red = red;
        }

        float Color::getGreen() const
        {
            return green;
        }

        void Color::setGreen(float green)
        {
            this->green = green;
        }

        float Color::getBlue() const
        {
            return blue;
        }

        void Color::setBlue(float blue)
        {
            this->blue = blue;
        }

        float Color::getAlpha() const
        {
            return alpha;
        }

        void Color::setAlpha(float alpha)
        {
            this->alpha = alpha;
        }
    };
};
