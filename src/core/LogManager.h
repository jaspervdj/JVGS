#ifndef JVGS_CORE_LOGMANAGER_H
#define JVGS_CORE_LOGMANAGER_H

#include <cstdio>

namespace jvgs
{
    namespace core
    {
        /** A simple singleton class to log messages.
         */
        class LogManager
        {
            protected:
                /** Constructor.
                 */
                LogManager();

                /** Destructor.
                 */
                ~LogManager();

            public:
                /** Obtain the singleton instance.
                 *  @return The LogManager instance.
                 */
                static LogManager *getInstance();

                /** Prints a message to the log file.
                 *  \param fmt Text, like passed to prinf in C.
                 */
                void message(const char *fmt, ...);

                /** Prints a warning to the log file.
                 *  \param fmt Text, like passed to prinf in C.
                 */
                void warning(const char *fmt, ...);

                /** Prints an error to the log file. And stops
                 *  the engine.
                 *  \param fmt Text, like passed to prinf in C.
                 */
                void error(const char *fmt, ...);
        };
    };
};

#endif
