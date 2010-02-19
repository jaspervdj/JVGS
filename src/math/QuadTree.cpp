#include "QuadTree.h"
#include "QuadTreeNode.h"
#include "BoundedObject.h"
#include "BoundingBox.h"
#include "Vector2D.h"

using namespace std;

namespace jvgs
{
    namespace math
    {
        QuadTree::QuadTree(vector<BoundedObject*> *objects, int subdivideLimit)
        {
            this->subdivideLimit = subdivideLimit;

            /* Initialize bounding box. */
            Vector2D topLeft, bottomRight;
            vector<BoundedObject*>::iterator iterator = objects->begin();
            while(iterator != objects->end() && !(*iterator)->getBoundingBox())
                iterator++;

            if(iterator != objects->end()) {

                topLeft = (*iterator)->getBoundingBox()->getTopLeft();
                bottomRight = (*iterator)->getBoundingBox()->getBottomRight();
                
                /* Expand bounding box. */
                for(iterator++; iterator != objects->end(); iterator++) {
                    BoundingBox *bb = (*iterator)->getBoundingBox();

                    /* Note that our bounding box could be 0, when we are
                     * dealing with a very small object. */
                    if(bb) {
                        if(bb->getTopLeft().getX() < topLeft.getX())
                            topLeft.setX(bb->getTopLeft().getX());
                        if(bb->getBottomRight().getX() > bottomRight.getX())
                            bottomRight.setX(bb->getBottomRight().getX());

                        if(bb->getTopLeft().getY() < topLeft.getY())
                            topLeft.setY(bb->getTopLeft().getY());
                        if(bb->getBottomRight().getY() > bottomRight.getY())
                            bottomRight.setY(bb->getBottomRight().getY());
                    }
                }

                root = new QuadTreeNode(this, 
                        new BoundingBox(topLeft, bottomRight));
                for(iterator = objects->begin(); iterator != objects->end();
                        iterator++) {
                    /* Only add objects with an actual bounding box. */
                    if((*iterator)->getBoundingBox())
                        root->addObject(*iterator);
                }

            /* No objects. */
            } else {
                root = 0;
            }
        }

        QuadTree::~QuadTree()
        {
            if(root)
                delete root;
        }

        int QuadTree::getSubdivideLimit() const
        {
            return subdivideLimit;
        }

        void QuadTree::findObjects(BoundingBox *boundingBox,
                std::vector<BoundedObject*> *result) const
        {
            if(root)
                root->findObjects(boundingBox, result);
        }
    }
}
