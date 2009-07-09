#ifndef JVGS_MATH_SEGMENTQUADTREENODE_H
#define JVGS_MATH_SEGMENTQUADTREENODE_H

#include "BoundingBox.h"
#include <vector>

namespace jvgs
{
    namespace math
    {
        class LineSegment;

        class SegmentQuadTreeNode
        {
            private:
                const static int SUBDIVIDE_LIMIT = 20;

                SegmentQuadTreeNode **children;
                BoundingBox boundingBox; 

                std::vector<LineSegment*> segments;

            public:
                SegmentQuadTreeNode(const BoundingBox &boundingBox);
                virtual ~SegmentQuadTreeNode();

                const BoundingBox &getBoundingBox() const;

                void addSegment(LineSegment *segment);

                void subdivide();

                virtual void dump(int indent) const;

                /** Find segments that intersect with a certain bounding box.
                 *  @param boundingBox BoundingBox to check intersection with.
                 *  @param result Where found line segments will be added to.
                 */
                virtual void findSegments(BoundingBox *boundingBox,
                        std::vector<LineSegment*> *result); 
        };
    }
}

#endif
