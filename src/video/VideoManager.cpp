#include "VideoManager.h"
#include "Renderer.h"

#include <SDL.h>
#include <SDL_opengl.h>

using namespace jvgs::math;

namespace jvgs
{
    namespace video
    {
        VideoManager::VideoManager()
        {
            SDL_InitSubSystem(SDL_INIT_VIDEO);
            flags = SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_HWACCEL | SDL_OPENGL;
        }

        VideoManager::~VideoManager()
        {
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
        }

        VideoManager *VideoManager::getInstance()
        {
            static VideoManager instance;
            return &instance;
        }

        void VideoManager::setVideoMode(std::string title)
        {
            SDL_Rect **modes = SDL_ListModes(NULL, flags | SDL_FULLSCREEN);

            /* Auto-select video mode. */
            size = Vector2D(800, 600);
            if(modes!=NULL) {
                size = Vector2D(modes[0]->w, modes[0]->h);
            }

            SDL_SetVideoMode((int) size.getX(), (int) size.getY(), 0,
                    flags | SDL_FULLSCREEN);
            SDL_ShowCursor(0);
            SDL_WM_SetCaption(title.c_str(), NULL);

            setVideoDefaults();
        }

        void VideoManager::setVideoMode(const Vector2D &size,
                                        std::string title)
        {
            this->size = Vector2D((int) size.getX(), (int) size.getY());

            SDL_SetVideoMode((int) size.getX(), (int) size.getY(), 0, flags);
            SDL_ShowCursor(0);
            SDL_WM_SetCaption(title.c_str(), NULL);
            
            setVideoDefaults();
        }

        void VideoManager::setVideoDefaults()
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0.0f, (GLfloat) size.getX(), (GLfloat) size.getY(), 
                    0.0f, -1.0f, 1.0f);

            glMatrixMode(GL_MODELVIEW);

            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, 0);

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glEnable(GL_LINE_SMOOTH);
            glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

            color = Color(0.0f, 0.0f, 0.0f);
            glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

            glLineWidth(1.5f);
        }

        const Vector2D &VideoManager::getSize() const
        {
            return size;
        }

        void VideoManager::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void VideoManager::flip() const
        {
            SDL_GL_SwapBuffers();
        }

        void VideoManager::identity() const
        {
            glLoadIdentity();
        }

        void VideoManager::push() const
        {
            glPushMatrix();
        }

        void VideoManager::pop() const
        {
            glPopMatrix();
        }

        void VideoManager::translate(const Vector2D &vector) const
        {
            glTranslatef(vector.getX(), vector.getY(), 0.0f);
        }

        void VideoManager::scale(const Vector2D &scale) const
        {
            glScalef(scale.getX(), scale.getY(), 1.0f);
        }

        void VideoManager::rotate(const float &degrees) const
        {
            glRotatef(degrees, 0.0f, 0.0f, 1.0f);
        }

        void VideoManager::transform(const AffineTransformationMatrix &matrix)
                const
        {
            float *glMatrix = new float[16];

            /* Our AffineTransformationMatrix
             *     / a b c \
             *     | d e f |
             *     \ 0 0 1 /
             * becomes a matrix we can use with OpenGL:
             *     / a b 0 c \
             *     | d e 0 f |
             *     | 0 0 1 0 |
             *     \ 0 0 0 1 /
             */

            /* Intialize to 0. */
            for(int i = 0; i < 16; i++)
                glMatrix[i] = 0.0f;
            
            for(int row = 0; row < matrix.getHeight(); row++) {
                for(int column = 0; column < matrix.getWidth(); column++) {
                    if(column < 2 && row < 2) {
                        glMatrix[column * 4 + row] =
                                matrix.getValue(row, column);
                    }
                }
            }

            glMatrix[2 * 4 + 2] = 1.0f;
            glMatrix[3 * 4 + 3] = 1.0f;

            glMatrix[3 * 4 + 0] = matrix.getValue(0, 2);
            glMatrix[3 * 4 + 1] = matrix.getValue(1, 2);

            glMultMatrixf(glMatrix);
            delete[] glMatrix;
        }

        void VideoManager::setColor(const Color &color)
        {
            this->color = color;
            glColor4f(color.getRed(), color.getGreen(),
                      color.getBlue(), color.getAlpha());
        }

        const Color &VideoManager::getColor() const
        {
            return color;
        }

        void VideoManager::setClearColor(const Color &clearColor)
        {
            this->clearColor = clearColor;
            glClearColor(color.getRed(), color.getGreen(),
                         color.getBlue(), color.getAlpha());
        }
    };
};
