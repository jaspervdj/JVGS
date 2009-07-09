#ifndef JVGS_MATH_SEGMENTQUADTREENODE_H
#define JVGS_MATH_SEGMENTQUADTREENODE_H

#include "BoundingBox.h"
#include "LineSegment.h"
#include <vector>

namespace jvgs
{
    namespace math
    {
        class SegmentQuadTreeNode
        {
            private:
                SegmentQuadTreeNode **children;
                BoundingBox boundingBox; 

                std::vector<LineSegment*> segments;

            public:
                SegmentQuadTreeNode(const BoundingBox &boundingBox);
                virtual ~SegmentQuadTreeNode();

                const BoundingBox &getBoundingBox() const;

                void addSegment(LineSegment *segment);

                void subdivide();
        };
    }
}

#endif
