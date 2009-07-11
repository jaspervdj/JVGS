#ifndef JVGS_MATH_SEGMENTQUADTREE_H
#define JVGS_MATH_SEGMENTQUADTREE_H

#include <vector>
#include "../math/BoundingBox.h"

namespace jvgs
{
    namespace math
    {
        class SegmentQuadTreeNode;
        class LineSegment;

        class SegmentQuadTree
        {
            private:
                /** Root of the tree. */
                SegmentQuadTreeNode *root;

            public:
                /** Constructor.
                 *  @param segments Segments to add. These will not be deleted.
                 */
                SegmentQuadTree(std::vector<LineSegment*> *segments);

                /** Destructor.
                 */
                virtual ~SegmentQuadTree();

                /** Find segments that intersect with a certain bounding box.
                 *  @param boundingBox BoundingBox to check intersection with.
                 *  @param result Where found line segments will be added to.
                 */
                virtual void findSegments(BoundingBox *boundingBox,
                        std::vector<LineSegment*> *result) const;
        };
    }
}

#endif
