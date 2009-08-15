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

    Font *font = new Font("resources/font.ttf", 40);
    videoManager->clear();
    videoManager->identity();
    videoManager->translate(Vector2D(50.0f, 50.0f));
    font->drawString("This is a quick test.");
    videoManager->flip();
    SDL_Delay(5000);

    delete font;
}
