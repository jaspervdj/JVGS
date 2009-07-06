#ifndef JVGS_GAME_LINESELECTOR_H
#define JVGS_GAME_LINESELECTOR_H

#include "../sketch/Sketch.h"
#include "../sketch/Group.h"
#include "../sketch/Path.h"
#include "../math/LineSegment.h"
#include <vector>

namespace jvgs
{
    namespace game
    {
        /** A class used to select certain lines from a whole
         *  bunch of lines, used for collision detection.
         */
        class LineSelector
        {
            private:
                std::vector<math::LineSegment*> segments;

            public:
                /** Constructor.
                 *  @param sketch Sketch to load lines from.
                 */
                LineSelector(sketch::Sketch *sketch);

                /** Destructor.
                 */
                virtual ~LineSelector();

                /** Add lines from a sketch group.
                 *  @param group Group to add the lines from.
                 */
                virtual void addLinesFromGroup(sketch::Group *group);

                /** Divide a path into lines and add the lines
                 *  to this selector.
                 *  @param path Path to add the lines from.
                 */
                virtual void addLinesFromPath(sketch::Path *path);
        };
    }
}

#endif
