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
    string fileName = argc < 2 ? string("resources/coloredtoucan-inkscape.svg")
            : string(argv[1]);

    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(Vector2D(800, 600), "(OpenGL window)");

    Sketch *sketch = new Sketch(fileName);
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    sketch->render();
    glEndList();

    float rotation = 0.0f;
    long start = SDL_GetTicks();
    while (SDL_GetTicks() < start + 15000) {

        long foo = SDL_GetTicks();
        videoManager->clear();
        glLoadIdentity();
        glTranslatef(200.0f, 200.0f, 0.0f);
        for(int i = 0; i < 10; i++) {
            videoManager->rotate(rotation);
            glCallList(list);
        }
        videoManager->flip();
        cout << (SDL_GetTicks() - foo) << endl;
        SDL_Delay(10);
        rotation += 0.1f;
    }

    glDeleteLists(list, 1);
    delete sketch;
    return 0;
}
