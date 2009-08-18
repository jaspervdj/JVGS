#ifndef JVGS_GAME_FLYSTRAIGHTCONTROLLER_H
#define JVGS_GAME_FLYSTRAIGHTCONTROLLER_H

#include "Controller.h"

namespace jvgs
{
    namespace game
    {
        /** A controller that keeps the velocity of the entity.
         */
        class FlyStraightController: public Controller
        {
            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 */
                FlyStraightController(Entity *entity);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                FlyStraightController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~FlyStraightController();

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
