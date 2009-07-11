#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

#include "../math/MathManager.h"
#include "../math/LineSegment.h"
#include "../math/Line.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../game/Entity.h"
#include "../game/CollisionResponseAffector.h"
#include "../game/GravityAffector.h"
using namespace jvgs::game;

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(200, 200, "Collision test.");

    Sketch *sketch = new Sketch("resources/world.svg");
    Sketch *ellipse = new Sketch("resources/ellipse.svg");
    Entity *entity = new Entity();
    entity->setEllipse(ellipse->getSize() / 2.0f);
    entity->setPosition(Vector2D(20.0f, 0.0f));

    CollisionResponseAffector *affector =
            new CollisionResponseAffector(entity, sketch);
    entity->addAffector(affector);

    GravityAffector *gravity = new GravityAffector(entity, Vector2D(0.0f, 0.5f));
    entity->addAffector(gravity);

    entity->prepare();

    bool running = true;
    while(running) {

        long start = SDL_GetTicks();

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT)
                running = false;
        }

        videoManager->clear();

        entity->update(1);

        sketch->render();

        videoManager->push();
        videoManager->translate(entity->getPosition() -
                ellipse->getSize() / 2.0f);
        ellipse->render();
        videoManager->pop();

        videoManager->flip();

        cout << "Frame in " << SDL_GetTicks() - start << "ms." << endl;

        SDL_Delay(100);
    }

    delete entity;
    delete sketch;
    delete ellipse;
}
