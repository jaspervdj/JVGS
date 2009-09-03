#ifndef JVGS_VIDEO_FPSLOGGER_H
#define JVGS_VIDEO_FPSLOGGER_H

#include "../core/View.h"

namespace jvgs
{
    namespace video
    {
        /** Simple class to log frames per second.
         */
        class FPSLogger: public core::View
        {
            private:
                /** Time since last updat3. */
                long time;

                /** Frames drawn since last beacon. */
                int frames;

            public:
                /** Constructor.
                 */
                FPSLogger();

                /** Destructor.
                 */
                virtual ~FPSLogger();

                /* Override
                 */
                virtual void update(float ms);

                /* Override
                 */
                virtual void render();
        };
    }
}

#endif
