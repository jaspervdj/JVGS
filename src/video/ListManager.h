#ifndef JVGS_VIDEO_LISTMANAGER_H
#define JVGS_VIDEO_LISTMANAGER_H

#include <GL/gl.h>

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

                /** Create and start a new list. Render commands executed
                 *  from now on will be stored in the list.
                 *  @return The new display list.
                 */
                List beginList() const;

                /** End the currently open display list. Render commands
                 *  will now be executed regularly.
                 */
                void endList() const;

                /** Execute a previously compiled display list.
                 *  @param list Display list to execute.
                 */
                void callList(const List &list) const;

                /** Delete a display list. After this, it would also be
                 *  a good idea not to call the list anymore.
                 *  @param list List to be deleted.
                 */
                void deleteList(List list) const;
        };
    }
}

#endif
