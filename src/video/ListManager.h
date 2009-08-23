#ifndef JVGS_VIDEO_LISTMANAGER_H
#define JVGS_VIDEO_LISTMANAGER_H

#include <SDL/SDL_opengl.h>

namespace jvgs
{
    namespace video
    {
        /** A class to manage display lists.
         */
        class ListManager
        {
            protected:
                /** Constructor.
                 */
                ListManager();

                /** Destructor.
                 */
                virtual ~ListManager();

            public:
                /** The data type used to store lists.
                 */
                typedef GLuint List;

                /** Get the ListManager instance.
                 *  @return The ListManager instance.
                 */
                static ListManager *getInstance();

                /** Create a number of new lists.
                 *  @param number Number of lists to create.
                 *  @return The first list created.
                 */
                List createLists(int number = 1) const;

                /** Start a new list. Render commands executed
                 *  from now on will be stored in the list.
                 *  @param list List to start.
                 */
                void beginList(const List &list) const;

                /** End the currently open display list. Render commands
                 *  will now be executed regularly.
                 */
                void endList() const;

                /** Execute a previously compiled display list.
                 *  @param list Display list to execute.
                 */
                void callList(const List &list) const;

                /** Execute a number of display lists.
                 *  @param base The first list.
                 *  @param lists Offsets to the lists.
                 *  @param number Number of lists.
                 */
                void callLists(const List &base, GLubyte *lists, int number)
                        const;

                /** Delete display lists. After this, it would also be
                 *  a good idea not to call the lists anymore.
                 *  @param base Base list to be deleted.
                 *  @param number Number of lists to be deleted.
                 */
                void deleteLists(const List &base, int number = 1) const;
        };
    }
}

#endif
