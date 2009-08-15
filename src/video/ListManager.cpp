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

        ListManager::List ListManager::createLists(int number) const
        {
            List list = glGenLists(number);
            return list;
        }

        void ListManager::beginList(const List &list) const
        {
            glNewList(list, GL_COMPILE);
        }

        void ListManager::endList() const
        {
            glEndList();
        }

        void ListManager::callList(const List &list) const
        {
            glCallList(list);
        }

        void ListManager::callLists(const List &base, GLubyte *lists,
                int number) const
        {
            glListBase(base);
            glCallLists(number, GL_UNSIGNED_BYTE, lists);
        }

        void ListManager::deleteLists(const List &list, int number) const
        {
            glDeleteLists(list, number);
        }
    }
}
