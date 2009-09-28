#ifndef JVGS_CORE_TIMEMANAGER_H
#define JVGS_CORE_TIMEMANAGER_H

namespace jvgs
{
    namespace core
    {
        class TimeManager
        {
            private:
            protected:
                /** Constructor.
                 */
                TimeManager();

                /** Destructor.
                 */
                virtual ~TimeManager();

            public:
                /** Get the TimeManager instance.
                 *  @return The TimeManager instance.
                 */
                static TimeManager *getInstance();

                /** Get the ticks since the engine was initialized in
                 *  milliseconds.
                 *  @return The ticks in milliseconds.
                 */
                long getTicks() const;

                /** Sleep for an amount of time.
                 *  @param ms Milliseconds to sleep.
                 */
                void sleep(int ms) const;
        };
    }
}

#endif
