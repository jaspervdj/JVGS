#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

#include "../bind/ScriptManager.h"
using namespace jvgs::bind;

#include "../input/InputManager.h"
using namespace jvgs::input;

#include "../math/MathManager.h"
#include "../math/LineSegment.h"
#include "../math/Line.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../game/Entity.h"
#include "../game/Sprite.h"
#include "../game/CollisionResponsePositioner.h"
#include "../game/InputController.h"
using namespace jvgs::game;

#include "../tinyxml/tinyxml.h"

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(Vector2D(400, 300), "Collision test.");

    InputManager *inputManager = InputManager::getInstance();

    Sketch *sketch = new Sketch("resources/world.svg");

    TiXmlDocument *document = new TiXmlDocument("resources/sprite.xml");
    document->LoadFile();
    Sprite *sprite = new Sprite(document->RootElement());
    delete document;

    Entity *entity = new Entity();
    entity->setRadius(Vector2D(25.0f, 41.0f));
    entity->setPosition(Vector2D(200.0f, 140.0f));
    entity->setController(new InputController(entity, 0.2f, 100.0f));
    entity->setPositioner(new CollisionResponsePositioner(entity, sketch,
            Vector2D(0.0f, 0.004f)));
    entity->setSprite(sprite);

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

        if(inputManager->isKeyDown(KEY_RETURN))
            videoManager->invert();

        videoManager->clear();

        if(ms > 0.0f)
            entity->update(ms);

        sketch->render();
        entity->render();

        videoManager->flip();

        SDL_Delay(10);
    }

    delete entity;
    delete sketch;

    return 0;
}
