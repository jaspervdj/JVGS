#ifndef JVGS_GAME_POSITIONERFACTORY_H
#define JVGS_GAME_POSITIONERFACTORY_H

#include "Positioner.h"
#include "AffectorFactory.h"

namespace jvgs
{
    namespace game
    {
        template <class T>
        class PositionerFactory: public AffectorFactory<Positioner>
        {
            public:
                /** Constructor.
                 */
                PositionerFactory()
                {
                }

                /** Destructor.
                 */
                virtual ~PositionerFactory()
                {
                }

                /* Override
                 */
                virtual Positioner *create(Entity *entity,
                        TiXmlElement *element) const
                {
                    return new T(entity, element);
                }
        };
    }
}

#endif
