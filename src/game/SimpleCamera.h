#ifndef JVGS_GAME_SIMPLECAMERA_H
#define JVGS_GAME_SIMPLECAMERA_H

#include "AbstractCamera.h"

namespace jvgs
{
    namespace game
    {
        class SimpleCamera: public AbstractCamera
        {
            private:
                /** Camera speed. */
                math::Vector2D velocity;

            protected:
                /* Override
                 */
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param position The camera position.
                 *  @param velocity The camera velocity.
                 *  @param level The camera level.
                 */
                SimpleCamera(const math::Vector2D &position,
                        const math::Vector2D &velocity, Level *level);

                /** Constructor.
                 *  @param element XML element to load data from.
                 *  @param level The camera level.
                 */
                SimpleCamera(TiXmlElement *element, Level *level);

                /** Destructor.
                 */
                virtual ~SimpleCamera();

                /** Get the camera velocity.
                 *  @return The camera velocity.
                 */
                virtual const math::Vector2D &getVelocity() const;

                /** Set the camera velocity.
                 *  @param velocity The new camera velocity.
                 */
                virtual void setVelocity(const math::Vector2D &Velocity);

                /* Override
                 */
                virtual void update(float ms);
        };
    }
}

#endif
