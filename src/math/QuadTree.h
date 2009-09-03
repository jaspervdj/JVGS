#ifndef JVGS_MATH_QUADTREE_H
#define JVGS_MATH_QUADTREE_H

#include <vector>

namespace jvgs
{
    namespace math
    {
        class QuadTreeNode;
        class BoundedObject;
        class BoundingBox;

        class QuadTree
        {
            private:
                /** Root of the tree. */
                QuadTreeNode *root;

                /** Nodes will subdivide when they have more bounded than
                 *  this limit. */
                int subdivideLimit;

            public:
                /** Constructor.
                 *  @param objects Objects to add. These will not be deleted.
                 *  @param subdivideLimit The subdivide limit.
                 */
                QuadTree(std::vector<BoundedObject*> *objects,
                        int subdivideLimit = 20);

                /** Destructor.
                 */
                virtual ~QuadTree();

                /** Get the subdivide limit.
                 *  @return The subdivide limit for this tree.
                 */
                virtual int getSubdivideLimit() const;

                /** Find objects that intersect with a certain bounding box.
                 *  @param boundingBox BoundingBox to check intersection with.
                 *  @param result Where found objects will be added to.
                 */
                virtual void findObjects(BoundingBox *boundingBox,
                        std::vector<BoundedObject*> *result) const;
        };
    }
}

#endif
