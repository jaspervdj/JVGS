#include "ListManager.h"

namespace jvgs
{
    namespace video
    {
        ListManager::ListManager()
        {
        }

        ListManager::~ListManager()
        {
        }

        ListManager *ListManager::getInstance()
        {
            static ListManager instance;
            return &instance;
        }

        ListManager::List ListManager::beginList() const
        {
            List list = glGenLists(1);
            glNewList(list, GL_COMPILE);
            return list;
        }

        void ListManager::endList() const
        {
            glEndList();
        }

        void ListManager::callList(const List &list) const
        {
            glCallList(list);
        }

        void ListManager::deleteList(List list) const
        {
            glDeleteLists(list, 1);
        }
    }
}
