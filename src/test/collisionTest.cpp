#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

#include "../bind/ScriptManager.h"
using namespace jvgs::bind;

#include "../math/MathManager.h"
#include "../math/LineSegment.h"
#include "../math/Line.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../game/Entity.h"
#include "../game/CollisionResponsePositioner.h"
#include "../game/InputController.h"
using namespace jvgs::game;

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(Vector2D(400, 300), "Collision test.");

    Sketch *sketch = new Sketch("resources/world.svg");
    Sketch *ellipse = new Sketch("resources/ellipse.svg");

    Entity *entity = new Entity();
    entity->setEllipse(ellipse->getSize() / 2.0f);
    entity->setPosition(Vector2D(200.0f, 150.0f));
    entity->setController(new InputController(entity, 0.1f, 500.0f));
    entity->setPositioner(new CollisionResponsePositioner(entity, sketch,
            Vector2D(0.0f, 0.25f)));

    ScriptManager *scriptManager = ScriptManager::getInstance();
    scriptManager->runCode("print(\"Hello world!\")");

    bool running = true;
    float ms = 0;
    long lastUpdate = SDL_GetTicks();
    while(running) {

        float now = SDL_GetTicks();
        ms = now - lastUpdate;
        lastUpdate = SDL_GetTicks();

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT)
                running = false;
        }

        videoManager->clear();

        entity->update(ms);

        sketch->render();

        videoManager->push();
        videoManager->translate(entity->getPosition() -
                ellipse->getSize() / 2.0f);
        ellipse->render();
        videoManager->pop();

        videoManager->flip();

        SDL_Delay(10);
    }

    delete entity;
    delete sketch;
    delete ellipse;
}
