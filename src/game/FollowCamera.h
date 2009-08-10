#ifndef JVGS_GAME_FOLLOWCAMERA_H
#define JVGS_GAME_FOLLOWCAMERA_H

#include "Camera.h"
#include "../math/Vector2D.h"

namespace jvgs
{
    namespace game
    {
        class Entity;

        class FollowCamera: public Camera
        {
            private:
                /** Object to follow. */
                Entity *entity;

                /** Max distance between camera focus and object. */
                float maxDistance;

                /** Current camera focus position. */
                math::Vector2D position;

            public:
                /** Constructor.
                 *  @param entity Object to follow.
                 *  @param maxDistance Max distance between focus and object.
                 */
                FollowCamera(Entity *entity, float maxDistance);

                /** Destructor.
                 */
                virtual ~FollowCamera();

                /* Override
                 */
                virtual void update(float ms);

                /* Override
                 */
                virtual void transform() const;
        };
    }
}

#endif
