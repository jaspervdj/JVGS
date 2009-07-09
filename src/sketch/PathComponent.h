#ifndef JVGS_SKETCH_PATHCOMPONENT_H
#define JVGS_SKETCH_PATHCOMPONENT_H

#include <vector>
#include "../math/PathSegment.h"
#include "../video/Renderer.h"

namespace jvgs
{
    namespace sketch
    {
        class Path;

        /** A component of a svg path.
         */
        class PathComponent
        {
            private:
                /** The path this component belongs to. */
                Path *path;

                /** The different segments in this component. */
                std::vector<math::PathSegment*> segments;

            public:
                /** Constructor.
                 *  @param path The path this component belongs to.
                 */
                PathComponent(Path *path);

                /** Destructor.
                 */
                virtual ~PathComponent();

                /** Get this component's path.
                 *  @return The path this component belongs to.
                 */
                virtual Path *getPath() const;

                /** Get the number of segments in this component.
                 *  @return The number of segments in this component.
                 */
                virtual int getNumberOfSegments() const;

                /** Get the segment with the given index.
                 *  @param index Index of the requested segment.
                 *  @return The requested segment.
                 */
                virtual math::PathSegment *getSegment(int index) const;

                /** Add a segment to this component.
                 *  @param segment PathSegment to add.
                 */
                virtual void addSegment(math::PathSegment *segment);

                /** Render this path component.
                 *  @param renderer Renderer to use.
                 */
                virtual void render(video::Renderer *renderer) const;
        };
    }
}
#endif
