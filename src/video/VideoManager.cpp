#include "VideoManager.h"
#include "Renderer.h"

#include <SDL.h>
#include <SDL_opengl.h>

#include <iostream>
using namespace std;

using namespace jvgs::math;

namespace jvgs
{
    namespace video
    {
        VideoManager::VideoManager()
        {
            SDL_InitSubSystem( SDL_INIT_VIDEO );
            flags = SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_HWACCEL | SDL_OPENGL;
        }

        VideoManager::~VideoManager()
        {
            SDL_QuitSubSystem( SDL_INIT_VIDEO );
        }

        VideoManager *VideoManager::getInstance()
        {
            static VideoManager instance;
            return &instance;
        }

        void VideoManager::setVideoMode( std::string title )
        {
            SDL_Rect **modes = SDL_ListModes( NULL, flags | SDL_FULLSCREEN );

            /* Auto-select video mode. */
            width = 800, height = 600;
            if( modes!=NULL ) {
                width = modes[0]->w;
                height = modes[0]->h;
            }

            SDL_SetVideoMode( width, height, 0, flags | SDL_FULLSCREEN );
            SDL_ShowCursor( 0 );
            SDL_WM_SetCaption( title.c_str(), NULL );

            setVideoDefaults();
        }

        void VideoManager::setVideoMode( int width, int height, std::string title )
        {
            this->width = width;
            this->height = height;

            SDL_SetVideoMode( width, height, 0, flags );
            SDL_ShowCursor( 0 );
            SDL_WM_SetCaption( title.c_str(), NULL );
            
            setVideoDefaults();
        }

        void VideoManager::setVideoDefaults() const
        {
            glMatrixMode( GL_PROJECTION );
            glLoadIdentity();
            glOrtho( 0.0f, (GLfloat)width, (GLfloat)height, 0.0f, -1.0f, 1.0f );

            glMatrixMode( GL_MODELVIEW );

            glEnable( GL_TEXTURE_2D );
            glBindTexture( GL_TEXTURE_2D, 0 );

            glEnable( GL_BLEND );
            glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

            glEnable( GL_LINE_SMOOTH );
            glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
            //glHint( GL_LINE_SMOOTH_HINT, GL_DONT_CARE );

            glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
            glColor4f( 0.0f, 0.0f, 0.0f, 1.0f );

            glLineWidth( 1.5f );
        }

        int VideoManager::getWidth() const
        {
            return width;
        }

        int VideoManager::getHeight() const
        {
            return height;
        }

        void VideoManager::clear() const
        {
            glClear( GL_COLOR_BUFFER_BIT );
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

        void VideoManager::translate( const float &x, const float &y ) const
        {
            glTranslatef( x, y, 0.0f );
        }

        void VideoManager::scale( const float &x, const float &y ) const
        {
            glScalef( x, y, 1.0f );
        }

        void VideoManager::rotate( const float &degrees ) const
        {
            glRotatef( degrees, 0.0f, 0.0f, 1.0f );
        }

        void VideoManager::transform(const AffineTransformationMatrix &matrix) const
        {
            float *glMatrix = new float[16];

            /* Intialize to 0. */
            for(int i = 0; i < 16; i++)
                glMatrix[i] = 0.0f;
            
            for(int row = 0; row < matrix.getHeight(); row++) {
                for(int column = 0; column < matrix.getWidth(); column++) {
                    if(column < 2 && row < 2) {
                        glMatrix[column * 4 + row] = matrix.getValue(row, column);
                    }
                }
            }

            glMatrix[2 * 4 + 2] = 1.0f;
            glMatrix[3 * 4 + 3] = 1.0f;

            glMatrix[3 * 4 + 0] = matrix.getValue(0, 2);
            glMatrix[3 * 4 + 1] = matrix.getValue(1, 2);

            cout << "----- AffineTransformationMatrix ------" << endl;

            for(int row = 0; row < 3; row++) {
                for(int column = 0; column < 3; column++) {
                    cout << matrix.getValue(row, column) << "   ";
                }
                cout << endl;
            }

            cout << "----- glMatrix ------" << endl;

            for(int row = 0; row < 4; row++) {
                for(int column = 0; column < 4; column++) {
                    cout << glMatrix[column * 4 + row] << "   ";
                }
                cout << endl;
            }

            cout << "-----------" << endl;

            glMultMatrixf(glMatrix);
            delete[] glMatrix;
        }

        void VideoManager::setColor( Color color ) const
        {
            glColor4f( color.getRed(), color.getGreen(),
                       color.getBlue(), color.getAlpha() );
        }

        void VideoManager::setClearColor( Color color ) const
        {
            glClearColor( color.getRed(), color.getGreen(),
                          color.getBlue(), color.getAlpha() );
        }
    };
};
