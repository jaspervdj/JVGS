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
#include "../game/CollisionResponseAffector.h"
#include "../game/InputAffector.h"
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
    entity->setPosition(Vector2D(100.0f, 0.0f));

    CollisionResponseAffector *affector =
            new CollisionResponseAffector(entity, sketch,
                    Vector2D(0.0f, 0.03f));
    entity->addAffector(affector);

    InputAffector *input = new InputAffector(entity);
    entity->addAffector(input);

    entity->prepare();

    ScriptManager *scriptManager = ScriptManager::getInstance();
    scriptManager->runCode("print(\"Hello world!\")");

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

        //cout << "Frame in " << SDL_GetTicks() - start << "ms." << endl;

        SDL_Delay(100);
    }

    delete entity;
    delete sketch;
    delete ellipse;
}
