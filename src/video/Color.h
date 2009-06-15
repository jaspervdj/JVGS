#ifndef JVGS_VIDEO_COLOR_H
#define JVGS_VIDEO_COLOR_H

namespace jvgs
{
    namespace video
    {
        /** Class that represents a color.
         *  The color is held in RGBA space.
         */
        class Color
        {
            private:
                float red, green, blue, alpha;

            public:
                /** Constructor.
                 *  @param red The red component.
                 *  @param green The green component.
                 *  @param blue The blue component.
                 *  @param alpha The alpha component.
                 */
                Color(float red = 1.0f, float green = 1.0f, float blue = 1.0f,
                      float alpha = 1.0f);

                /** Destructor.
                 */
                virtual ~Color();

                /** Assignment operator.
                 */
                virtual const Color &operator=(const Color &other);

                /** Get the red component.
                 *  @return The red color component.
                 */
                virtual float getRed() const;

                /** Set the red component.
                 *  @param red The red color component.
                 */
                virtual void setRed(float red);

                /** Get the green component.
                 *  @return The green color component.
                 */
                virtual float getGreen() const;

                /** Set the green component.
                 *  @param green The green color component.
                 */
                virtual void setGreen(float green);

                /** Get the blue component.
                 *  @return The blue color component.
                 */
                virtual float getBlue() const;

                /** Set the blue component.
                 *  @param blue The blue color component.
                 */
                virtual void setBlue(float blue);

                /** Get the alpha component.
                 *  @return The alpha color component.
                 */
                virtual float getAlpha() const;

                /** Set the alpha component.
                 *  @param alpha The alpha color component.
                 */
                virtual void setAlpha(float alpha);
        };
    };
};

#endif
