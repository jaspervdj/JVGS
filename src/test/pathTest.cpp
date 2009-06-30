#include "../sketch/Path.h"
#include "../sketch/PathComponent.h"
using namespace jvgs::sketch;

#include "../math/LineSegment.h"
#include "../math/CubicCurve.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

int main(int argc, char **argv)
{
    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(400, 300, "Path test.");

    Path *path = new Path(0);
    PathComponent *component = new PathComponent(path);
    component->addSegment(new LineSegment(Vector2D(30, 30), Vector2D(120, 50)));
    path->addComponent(component);

    Renderer *renderer = new Renderer();

    videoManager->clear();
    path->render(renderer);
    videoManager->flip();
    SDL_Delay(5000);

    delete path;
    delete renderer;
}
