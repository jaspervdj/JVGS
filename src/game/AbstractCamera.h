#ifndef JVGS_GAME_ABSTRACTCAMERA_H
#define JVGS_GAME_ABSTRACTCAMERA_H

#include "Camera.h"
#include "../math/Vector2D.h"
#include "../math/BoundingBox.h"
#include "../core/XMLLoadable.h"

namespace jvgs
{
    namespace game
    {
        class AbstractCamera: public Camera, public core::XMLLoadable
        {
            private:
                /** Camera position. */
                math::Vector2D position;

                /** Bounding box. */
                math::BoundingBox boundingBox;

            protected:
                /* Override
                 */
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param position Position for the camera.
                 *  @param level The camera level.
                 */
                AbstractCamera(const math::Vector2D &position, Level *level);

                /** Constructor
                 *  @param element XML element to load the data from.
                 *  @param level The camera level.
                 */
                AbstractCamera(TiXmlElement *element, Level *level);

                /** Destructor.
                 */
                virtual ~AbstractCamera();

                /** Get the camera position.
                 *  @return The camera position.
                 */
                virtual const math::Vector2D &getPosition() const;

                /** Set the camera position.
                 *  @param position The new camera position.
                 */
                virtual void setPosition(const math::Vector2D &position);

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
