#ifndef JVGS_GAME_CAMERA_H
#define JVGS_GAME_CAMERA_H

#include "../math/BoundedObject.h"

namespace jvgs
{
    namespace game
    {
        class Level;

        /** Abstract camera class.
         */
        class Camera: public math::BoundedObject
        {
            private:
                /** Level the camera is in. */
                Level *level;

            public:
                /** Constructor.
                 */
                Camera(Level *level);

                /** Destructor.
                 */
                virtual ~Camera();

                /** Get the level the camera is used for.
                 *  @return The camera level.
                 */
                virtual Level *getLevel() const;

                /** Update the camera.
                 *  @param ms Milliseconds to update for.
                 */
                virtual void update(float ms) = 0;

                /** Transform the current matrices so the scene will be rendered
                 *  correctly.
                 */
                virtual void transform() const = 0;
        };
    }
}

#endif
