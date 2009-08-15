#include "../font/Font.h"
using namespace jvgs::font;

#include "../video/VideoManager.h"
using namespace jvgs::video;

#include "../math/Vector2D.h"
using namespace jvgs::math;

int main(int argc, char **argv)
{
    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(Vector2D(400, 300), "Font test.");

    videoManager->clear();
    videoManager->translate(Vector2D(150.0f, 150.0f));
    //videoManager->scale(Vector2D(0.1f, 0.1f));
    Font *font = new Font("resources/font.ttf", 100);
    videoManager->flip();
    SDL_Delay(5000);

    delete font;
}
