#ifndef JVGS_MATH_QUADTREENODE_H
#define JVGS_MATH_QUADTREENODE_H

#include <vector>

namespace jvgs
{
    namespace math
    {
        class BoundingBox;
        class BoundedObject;

        /** A node containing some bounded objects. This node is able to
         *  subdivide aka. spawn children.
         */
        class QuadTreeNode
        {
            private:
                /** Nodes will subdivide when they have more bounded than
                 *  this limit. */
#               ifndef SWIG
                    const static int SUBDIVIDE_LIMIT = 20;
#               else
                    static int SUBDIVIDE_LIMIT = 20;
#               endif

                /** Children of the node. 0 if no children yet. */
                QuadTreeNode **children;

                /** Bounding box of this node's area. */
                BoundingBox *boundingBox; 

                /** The objects belonging to this node. */
                std::vector<BoundedObject*> objects;

            public:
                /** Constructor.
                 *  @param boundingBox Bounding box for this node's area.
                 */
                QuadTreeNode(BoundingBox *boundingBox);

                /** Destructor.
                 */
                virtual ~QuadTreeNode();

                /** Get the bounding box for this node's area.
                 *  @return The bounding box for this node's area.
                 */
                BoundingBox *getBoundingBox() const;

                /** Add a bounded object. This will automatically cause
                 *  subdivision when a certain limit is reached.
                 *  @param object BoundedObject to add.
                 */
                void addObject(BoundedObject *object);

                /** Force subdivision of this node. You better have a good
                 *  fucking reason to use this.
                 */
                void subdivide();

                /** Find objects that intersect with a certain bounding box.
                 *  @param boundingBox BoundingBox to check intersection with.
                 *  @param result Where found objects will be added to.
                 */
                virtual void findObjects(BoundingBox *boundingBox,
                        std::vector<BoundedObject*> *result); 
        };
    }
}

#endif
