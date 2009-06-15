#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string fileName = argc < 2 ? string("resources/drawing.svg") :
                                 string(argv[1]);

    Sketch *sketch = new Sketch(fileName);
    Vector2D size = sketch->getSize();

    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(size.getX(), size.getY(),
            string("(OpenGL window)") );

    videoManager->clear();
    long start = SDL_GetTicks();
    sketch->render();
    while (SDL_GetTicks() < start + 5000) {
        videoManager->flip();
        SDL_Delay(10);
    }

    delete sketch;
    return 0;
}
