#ifndef JVGS_MATH_SEGMENTQUADTREENODE_H
#define JVGS_MATH_SEGMENTQUADTREENODE_H

#include "BoundingBox.h"
#include <vector>

namespace jvgs
{
    namespace math
    {
        class LineSegment;

        /** A node containing some line segments. This node is able to
         *  subdivide aka. spawn children.
         */
        class SegmentQuadTreeNode
        {
            private:
                /** Nodes will subdivide when they have more segments than
                 *  this limit. */
#               ifndef SWIG
                    const static int SUBDIVIDE_LIMIT = 20;
#               else
                    static int SUBDIVIDE_LIMIT = 20;
#               endif

                /** Children of the node. 0 if no children yet. */
                SegmentQuadTreeNode **children;

                /** Bounding box of this node's area. */
                BoundingBox boundingBox; 

                /** The segments belonging to this node. */
                std::vector<LineSegment*> segments;

            public:
                /** Constructor.
                 *  @param boundingBox Bounding box for this node's area.
                 */
                SegmentQuadTreeNode(const BoundingBox &boundingBox);

                /** Destructor.
                 */
                virtual ~SegmentQuadTreeNode();

                /** Get the bounding box for this node's area.
                 *  @return The bounding box for this node's area.
                 */
                const BoundingBox &getBoundingBox() const;

                /** Add a segment. This will automatically cause subdivision
                 *  when a certain limit is reached.
                 *  @param segment LineSegment to add.
                 */
                void addSegment(LineSegment *segment);

                /** Force subdivision of this node. You better have a good
                 *  fucking reason to use this.
                 */
                void subdivide();

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
