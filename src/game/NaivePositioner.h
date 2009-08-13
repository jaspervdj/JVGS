#ifndef JVGS_GAME_NAIVEPOSITIONER_H
#define JVGS_GAME_NAIVEPOSITIONER_H

#include "Positioner.h"

namespace jvgs
{
    namespace game
    {
        class NaivePositioner: public Positioner
        {
            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to position.
                 */
                NaivePositioner(Entity *entity);

                /** Constructor
                 *  @param entity Entity to position.
                 *  @param element TiXmlElement containing the data.
                 */
                NaivePositioner(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~NaivePositioner();

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
