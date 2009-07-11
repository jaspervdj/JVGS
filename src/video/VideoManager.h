#ifndef JVGS_VIDEO_VIDEOMANAGER_H
#define JVGS_VIDEO_VIDEOMANAGER_H

#include "Color.h"
#include "../math/AffineTransformationMatrix.h"
#include "../math/Vector2D.h"
#include <string>
#include <SDL/SDL.h>

namespace jvgs
{
    namespace video
    {
        class Renderer;

        /** A singleton class that manages video information.
         *  It also allows you to set video options. To draw,
         *  use a Renderer class.
         */
        class VideoManager
        {
            private:
                /* Video flags used. */
                Uint32 flags;

                /* Video dimensions. */
                int width, height;

                /* Drawing color. */
                Color color;

            protected:
                /** Constructor.
                 */
                VideoManager();

                /** Desturctor.
                 */
                ~VideoManager();

            public:
                static VideoManager *getInstance();

                /** This will attempt to choose the best fitting video
                 *  mode. Usually this is fullscreen, with the native
                 *  screen resolution.
                 *  \param title Title to be fed to the window manager.
                 */
                void setVideoMode(std::string title);

                /** Sets a windowed video mode with the given dimensions.
                 *  \param width The screen width.
                 *  \param height The screen height.
                 *  \param title Title to be fed to the window manager.
                 */
                void setVideoMode(int width, int height, std::string title);

                /** Sets a number of (good!) default flags. This includes
                 *  blending mode, textures enabled, the correct projection
                 *  matrix, the identity modelview matrix... for the full
                 *  list, well, see the source code.
                 */
                void setVideoDefaults();

                /** Get the screen width.
                 *  \return The screen width.
                 */
                int getWidth() const;

                /** Get the screen height.
                 *  \return The screen height.
                 */
                int getHeight() const;

                /** Clears the screen.
                 */
                void clear() const;

                /** Flips the buffer.
                 */
                void flip() const;

                /** Restores the identity matrix.
                 */
                void identity() const;

                /** Pushes the current matrix onto the stack.
                 */
                void push() const;

                /** Pops the previous matrix from the stack.
                 */
                void pop() const;

                /** Translates the current matrix.
                 *  @param vector Vector to translate over.
                 */
                void translate(const math::Vector2D &vector) const;

                /** Scales the current matrix.
                 *  @param scale Vector to be used as scale.
                 */
                void scale(const math::Vector2D &scale) const;

                /** Rotates the current matrix.
                 *  @param degrees Rotation degrees.
                 */
                void rotate(const float &degrees) const;

                /** Tranforms with a tranformation matrix.
                 *  @param matrix The tranformation matrix.
                 */
                void transform(const math::AffineTransformationMatrix &matrix)
                        const;

                /** Select a color for drawing.
                 *  @param color Color to be used.
                 */
                virtual void setColor(Color color); 

                /** Get the drawing color.
                 *  @return The current drawing color.
                 */
                virtual const Color &getColor() const;

                /** Select a color for clearing the screen.
                 *  @param color Color to be used.
                 */
                virtual void setClearColor(Color color) const;
        };
    };
};

#endif
