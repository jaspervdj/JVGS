#ifndef JVGS_GAME_BULLCONTROLLER_H
#define JVGS_GAME_BULLCONTROLLER_H

#include "Controller.h"
#include <string>

namespace jvgs
{
    namespace game
    {
        /** A controller that makes an entity storm towards another entity
         *  on detection, just like a bull.
         */
        class BullController: public Controller
        {
            private:
                /** Id of the target entity. */
                std::string target;

                /** Sight distance. */
                float sight;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param target Id of the target entity.
                 *  @param sight Sight distance.
                 */
                BullController(Entity *entity, const std::string &target,
                        float sight);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                BullController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~BullController();

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
