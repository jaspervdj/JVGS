#ifndef JVGS_GAME_SILLYCONTROLLER_H
#define JVGS_GAME_SILLYCONTROLLER_H

#include "Controller.h"

namespace jvgs
{
    namespace game
    {
        /** A silly controller that makes the entity walk arround.
         */
        class SillyController: public Controller
        {
            private:
                /** When the velocity goes under this treshold, the entity will
                 *  change direction. Between 0 and 1. */
                float speedTreshold;

                /** If we're walking right. */
                bool walkingRight;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param speedTreshold Direction change treshold.
                 */
                SillyController(Entity *entity, float speedTreshold);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element XML element to load data from.
                 */
                SillyController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~SillyController();

                /* Override.
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
