#ifndef JVGS_EFFECT_TEXTEFFECT_H
#define JVGS_EFFECT_TEXTEFFECT_H

#include "../core/View.h"
#include "../font/Font.h"
#include "../math/Vector2D.h"
#include <string>

namespace jvgs
{
    namespace effect
    {
        class TextEffect: public core::View
        {
            private:
                /** Text of the effect. */
                std::string text;

                /** Position. */
                math::Vector2D position;

                /** Life lift. */
                float life;

                /** Font used. */
                font::Font *font;

                /** Width of the text. */
                float width;

            public:
                /** Constructor.
                 */
                TextEffect(const std::string &text, const math::Vector2D
                        &position, float life);

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
