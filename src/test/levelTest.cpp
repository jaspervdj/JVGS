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
#include "../game/Level.h"
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

    TiXmlDocument *document = new TiXmlDocument("resources/level.xml");
    document->LoadFile();
    Level *level = new Level(document->RootElement());
    delete document;

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

        if(ms > 0.0f)
            level->update(ms);

        level->render();

        videoManager->flip();

        SDL_Delay(10);
    }

    delete level;

    return 0;
}
