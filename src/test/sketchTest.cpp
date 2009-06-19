#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

#include <GL/gl.h>

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    string fileName = argc < 2 ? string("resources/drawing.svg") :
                                 string(argv[1]);

    long start = SDL_GetTicks();
    Sketch *sketch = new Sketch(fileName);
    cout << "Parsed sketch in " << (SDL_GetTicks() - start) << "ms." << endl;

    Vector2D size = sketch->getSize();

    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(size.getX(), size.getY(),
            string("(OpenGL window)") );

    videoManager->clear();

    start = SDL_GetTicks();
    sketch->render();
    cout << "Rendered sketch in " << (SDL_GetTicks() - start) << "ms." << endl;
    
    videoManager->flip();

    start = SDL_GetTicks();
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    sketch->render();
    glEndList();
    cout << "Compiled list in " << (SDL_GetTicks() - start) << "ms." << endl;

    videoManager->clear();

    start = SDL_GetTicks();
    glCallList(list);
    cout << "Called list in " << (SDL_GetTicks() - start) << "ms." << endl;

    glDeleteLists(list, 1);

    while (SDL_GetTicks() < start + 15000) {
        videoManager->flip();
        SDL_Delay(10);
    }

    delete sketch;
    return 0;
}
