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

            public:
                /** Constructor.
                 *  @param objects Objects to add. These will not be deleted.
                 */
                QuadTree(std::vector<BoundedObject*> *objects);

                /** Destructor.
                 */
                virtual ~QuadTree();

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
