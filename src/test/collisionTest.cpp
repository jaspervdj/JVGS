#include "../video/VideoManager.h"
#include "../video/Renderer.h"
using namespace jvgs::video;

#include "../math/Ellipse.h"
#include "../math/MathManager.h"
#include "../math/LineSegment.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../sketch/Sketch.h"
using namespace jvgs::sketch;

#include <vector>
using namespace std;

class CollisionObject: public Ellipse
{
    public:
        Vector2D position;

        CollisionObject(Vector2D radius): Ellipse(radius)
        {
        }
};

int main(int argc, char **argv)
{
    const static int width = 480, height = 380;

    VideoManager *videoManager = VideoManager::getInstance();
    videoManager->setVideoMode(width, height, "Collision test.");
    Renderer *renderer = new Renderer();

    MathManager *mathManager = MathManager::getInstance();

    /* Initialize lines. */
    vector<LineSegment> lines;
    for(int i = 0; i < 20; i++) {
        Vector2D p1 = Vector2D(mathManager->randFloat(width),
                mathManager->randFloat(height));
        Vector2D p2 = Vector2D(mathManager->randFloat(width),
                mathManager->randFloat(height));
        lines.push_back(LineSegment(p1, p2));
    }

    /* Initialize collision object. */
    Sketch *sketch = new Sketch("resources/ellipse.svg");
    CollisionObject *collisionObject = new CollisionObject(sketch->getSize());

    bool running = true;
    while(running) {

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT)
                running = false;
        }

        int x, y;
        SDL_GetMouseState(&x, &y);
        Vector2D newPosition = Vector2D(x, y);

        collisionObject->position = newPosition;

        videoManager->clear();

        for(vector<LineSegment>::iterator iterator = lines.begin();
                iterator != lines.end(); iterator++) {
            renderer->begin(Renderer::LINE_STRIP);
            renderer->vector(iterator->getPoint(0.0f));
            renderer->vector(iterator->getPoint(1.0f));
            renderer->end();
        }

        videoManager->push();
        videoManager->translate(collisionObject->position);
        sketch->render();
        videoManager->pop();

        videoManager->flip();
    }

    delete collisionObject;
    delete sketch;
}
