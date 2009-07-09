#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

#include "../math/MathManager.h"
#include "../math/LineSegment.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include "../game/Entity.h"
#include "../game/CollisionResponder.h"
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
    entity->setPosition(Vector2D(0.0f, 0.0f));
    entity->setVelocity(Vector2D(5.0f, 5.0f));

    CollisionResponder *responder = new CollisionResponder(entity, sketch);

    bool running = true;
    while(running) {

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT)
                running = false;
        }

        Vector2D collision;
        float time = 100.0f;
        LineSegment *segment;

        const int number = 500;
        long start = SDL_GetTicks();
        for(int i = 0; i < number; i++) {
            segment = responder->closestCollision(1, &collision, &time);
        }
        cout << number << " collision tests in " << SDL_GetTicks() - start <<
                "ms." << endl;

        if(!segment)
            entity->setPosition(entity->getPosition() + entity->getVelocity());

        videoManager->clear();

        sketch->render();

        videoManager->push();
        videoManager->translate(entity->getPosition() -
                ellipse->getSize() / 2.0f);
        ellipse->render();
        videoManager->pop();

        if(segment) {
            glColor3f(1.0f, 0.0f, 0.0f);
            /*glBegin(GL_POINTS);
            glVertex2f(collision.getX(), collision.getY());
            glEnd();*/
            glBegin(GL_LINES);
            glVertex2f(segment->getStart().getX() * entity->getEllipse().getX(),
                    segment->getStart().getY() * entity->getEllipse().getY());
            glVertex2f(segment->getEnd().getX() * entity->getEllipse().getX(),
                    segment->getEnd().getY() * entity->getEllipse().getY());
            glEnd();
            glColor3f(0.0f, 0.0f, 0.0f);
        }

        videoManager->flip();

        SDL_Delay(1000);
    }

    delete entity;
    delete responder;
    delete sketch;
    delete ellipse;
}
