#ifndef JVGS_GAME_COLLISIONDESTROYPOSITIONER_H
#define JVGS_GAME_COLLISIONDESTROYPOSITIONER_H

#include "../math/CollisionDetector.h"
#include "Positioner.h"

namespace jvgs
{
    namespace game
    {
        class CollisionDestroyPositioner: public Positioner
        {
            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to destroy on collisions.
                 */
                CollisionDestroyPositioner(Entity *entity);

                /** Constructor.
                 *  @param entity Entity to destroy on collisions.
                 *  @param element TiXmlElement containing the data.
                 */
                CollisionDestroyPositioner(Entity *entity,
                        TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~CollisionDestroyPositioner();

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
