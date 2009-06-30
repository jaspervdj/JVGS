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
            private:
                /** Constructor.
                 */
                ListManager();

                /** Destructor.
                 */
                virtual ~ListManager();

            public:
                typedef GLuint List;

                static ListManager *getInstance();

                List beginList() const;
                void endList() const;

                void callList(const List &list) const;
        };
    }
}

#endif
