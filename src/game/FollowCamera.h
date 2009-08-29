#ifndef JVGS_GAME_FOLLOWCAMERA_H
#define JVGS_GAME_FOLLOWCAMERA_H

#include "Camera.h"
#include "../math/Vector2D.h"
#include "../math/BoundingBox.h"
#include "../core/XMLLoadable.h"
#include <string>

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

                /** Id of object to follow. */
                std::string target;

                /** Max distance between camera focus and object. */
                float maxDistance;

                /** Current camera focus position. */
                math::Vector2D position;

                /** Bounding box. */
                math::BoundingBox boundingBox;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param target Id of target to follow.
                 *  @param maxDistance Max distance between focus and object.
                 *  @param level Level the camera is used for.
                 */
                FollowCamera(const std::string &target, float maxDistance,
                        Level *level);

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

                /* Override
                 */
                virtual math::BoundingBox *getBoundingBox();
        };
    }
}

#endif
