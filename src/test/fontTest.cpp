#include "../font/Font.h"
using namespace jvgs::font;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if(argc != 2) {
        cout << "Usage: " << argv[0] << " text" << endl;
        return 1;
    }

    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(Vector2D(400, 300), "Font test.");

    Font *font = new Font("resources/font.ttf", 40);
    videoManager->clear();
    videoManager->identity();
    videoManager->translate(Vector2D(50.0f, 50.0f));
    font->drawString(string(argv[1]));
    videoManager->flip();
    SDL_Delay(5000);

    delete font;
}
