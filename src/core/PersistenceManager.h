#ifndef JVGS_CORE_PERSISTENCEMANAGER_H
#define JVGS_CORE_PERSISTENCEMANAGER_H

#include "PropertyMap.h"

namespace jvgs
{
    namespace core
    {
        class PersistenceManager: public core::PropertyMap
        {
            protected:
                /** Constructor.
                 */
                PersistenceManager();

                /** Destructor.
                 */
                virtual ~PersistenceManager();

            public:
                /** Get the PersistenceManager instance.
                 *  @return The PersistenceManager instance.
                 */
                static PersistenceManager *getInstance();
        };
    }
}

#endif
