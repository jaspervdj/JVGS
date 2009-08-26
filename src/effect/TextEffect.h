#ifndef JVGS_EFFECT_TEXTEFFECT_H
#define JVGS_EFFECT_TEXTEFFECT_H

#include "LifeEffect.h"
#include "../font/Font.h"
#include "../math/Vector2D.h"
#include <string>

namespace jvgs
{
    namespace effect
    {
        class TextEffect: public LifeEffect
        {
            private:
                /** Text of the effect. */
                std::string text;

                /** Position. */
                math::Vector2D position;

                /** Rotation speed. */
                float rotationSpeed;

                /** Font used. */
                font::Font *font;

                /** Width of the text. */
                float width;

                /** Current rotation. */
                float rotation;

            public:
                /** Constructor.
                 *  @param text Text to display.
                 *  @param position Position for the text.
                 *  @param life Lifetime in milliseconds.
                 *  @param rotationSpeed Speed to rotate the text with.
                 */
                TextEffect(const std::string &text, const math::Vector2D
                        &position, float life = 2000,
                        float rotationSpeed = 0.1f);

                /** Destructor.
                 */
                virtual ~TextEffect();

                /* Override
                 */
                virtual void update(float ms);

                /* Override
                 */
                virtual void render();
        };
    }
}

#endif
