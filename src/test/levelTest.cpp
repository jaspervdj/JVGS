#include "../video/VideoManager.h"
using namespace jvgs::video;
using namespace jvgs::math;

#include "../game/LevelManager.h"
using namespace jvgs::game;

int main(int argc, char **argv)
{
    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(Vector2D(400, 300), "Collision test.");

    LevelManager *levelManager = LevelManager::getInstance();
    levelManager->queueLevel("resources/level.xml");

    levelManager->run();

    return 0;
}
