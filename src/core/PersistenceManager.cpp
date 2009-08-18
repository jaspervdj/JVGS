#include "PersistenceManager.h"

namespace jvgs
{
    namespace core
    {
        PersistenceManager::PersistenceManager()
        {
        }

        PersistenceManager::~PersistenceManager()
        {
        }

        PersistenceManager *PersistenceManager::getInstance()
        {
            static PersistenceManager instance;
            return &instance;
        }
    }
}
