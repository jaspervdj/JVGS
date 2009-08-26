#include "Particle.h"

#include "../video/VideoManager.h"
using namespace jvgs::video;

using namespace jvgs::math;
using namespace jvgs::sketch;

namespace jvgs
{
    namespace effect
    {
        Particle::Particle(Sketch *sketch, float life,
                const Vector2D &position, const Vector2D &velocity,
                const Vector2D &gravity): LifeEffect(life)
        {
            this->sketch = sketch;
            this->position = position;
            this->velocity = velocity;
            this->gravity = gravity;
        }

        Particle::~Particle()
        {
        }

        void Particle::update(float ms)
        {
            LifeEffect::update(ms);
            position += velocity * ms;
            velocity += gravity * ms;
        }

        void Particle::render()
        {
            VideoManager *videoManager = VideoManager::getInstance();
            videoManager->push();
            videoManager->translate(position);
            sketch->render();
            videoManager->pop();
        }
    }
}
