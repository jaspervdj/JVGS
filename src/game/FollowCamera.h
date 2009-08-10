#ifndef JVGS_GAME_FOLLOWCAMERA_H
#define JVGS_GAME_FOLLOWCAMERA_H

#include "Camera.h"
#include "../math/Vector2D.h"
#include "../core/XMLLoadable.h"

namespace jvgs
{
    namespace game
    {
        class Entity;
        class Level;

        class FollowCamera: public Camera, public core::XMLLoadable
        {
            private:
                /** Level the camera is in. */
                Level *level;

                /** Object to follow. */
                Entity *entity;

                /** Max distance between camera focus and object. */
                float maxDistance;

                /** Current camera focus position. */
                math::Vector2D position;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Object to follow.
                 *  @param maxDistance Max distance between focus and object.
                 *  @param level Level the camera is used for.
                 */
                FollowCamera(Entity *entity, float maxDistance, Level *level);

                /** Constructor.
                 *  @param element XML element to load data from.
                 *  @param level Level the camera is used for.
                 */
                FollowCamera(TiXmlElement *element, Level *level);

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
