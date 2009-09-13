#ifndef JVGS_SKETCH_SKETCHMANAGER_H
#define JVGS_SKETCH_SKETCHMANAGER_H

#include <map>
#include <string>

namespace jvgs
{
    namespace sketch
    {
        class Sketch;

        /** A class that manages sketches as resources. */
        class SketchManager
        {
            private:
                /** Map storing the sketches by name. */
                std::map<std::string, Sketch*> sketches;

            protected:
                /** Constructor.
                 */
                SketchManager();

                /** Destructor.
                 */
                virtual ~SketchManager();
            
            public:
                /** Get the SketchManager instance.
                 *  @return The SketchManager instance.
                 */
                static SketchManager *getInstance();

                /** Clear all sketches.
                 */
                void clear();

                /** Load a sketch or fetch it from the cache if available.
                 *  @param fileName File name of the file to load.
                 *  @return The requested sketch.
                 */
                Sketch *getSketch(const std::string &fileName);
        };
    }
}

#endif
