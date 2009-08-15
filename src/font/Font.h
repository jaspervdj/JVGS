#ifndef JVGS_FONT_FONT_H
#define JVGS_FONT_FONT_H

#include <string>
#include "../sketch/Sketch.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
#include <ft2build.h>
#include FT_FREETYPE_H

namespace jvgs
{
    namespace font
    {
        class Font
        {
            private:
                /** Transformation matrix for points. */
                math::AffineTransformationMatrix matrix;

                /** Font size. */
                float size;

            public:
                /** Constructor.
                 *  @param fileName File name of the font to load.
                 *  @param size Pixel size for the font.
                 */
                Font(const std::string &fileName, float size);

                /** Destructor.
                 */
                virtual ~Font();

                virtual sketch::Sketch *createSketch(FT_Outline *outline);

                virtual math::Vector2D toVector(const FT_Vector &point) const;
        };
    }
}

#endif
