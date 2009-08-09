#ifndef JVGS_GAME_CONTROLLERFACTORY_H
#define JVGS_GAME_CONTROLLERFACTORY_H

#include "Controller.h"
#include "AffectorFactory.h"

namespace jvgs
{
    namespace game
    {
        template <class T>
        class ControllerFactory: public AffectorFactory<Controller>
        {
            public:
                /** Constructor.
                 */
                ControllerFactory()
                {
                }

                /** Destructor.
                 */
                virtual ~ControllerFactory()
                {
                }

                /* Override
                 */
                virtual Controller *create(Entity *entity,
                        TiXmlElement *element) const
                {
                    return new T(entity, element);
                }
        };
    }
}

#endif
