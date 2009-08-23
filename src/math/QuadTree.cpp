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
        QuadTree::QuadTree(vector<BoundedObject*> *objects)
        {
            /* Initialize bounding box. */
            Vector2D topLeft, bottomRight;
            vector<BoundedObject*>::iterator iterator = objects->begin();
            if(objects->begin() != objects->end()) {

                topLeft = (*iterator)->getBoundingBox()->getTopLeft();
                bottomRight = (*iterator)->getBoundingBox()->getBottomRight();
                
                /* Expand bounding box. */
                for(iterator++; iterator != objects->end(); iterator++) {
                    BoundingBox *boundingBox = (*iterator)->getBoundingBox();

                    if(boundingBox->getTopLeft().getX() < topLeft.getX())
                        topLeft.setX(boundingBox->getTopLeft().getX());
                    if(boundingBox->getBottomRight().getX() > bottomRight.getX())
                        bottomRight.setX(boundingBox->getBottomRight().getX());

                    if(boundingBox->getTopLeft().getY() < topLeft.getY())
                        topLeft.setY(boundingBox->getTopLeft().getY());
                    if(boundingBox->getBottomRight().getY() > bottomRight.getY())
                        bottomRight.setY(boundingBox->getBottomRight().getY());
                }

                root = new QuadTreeNode(new BoundingBox(topLeft, bottomRight));
                for(iterator = objects->begin(); iterator != objects->end();
                        iterator++) {
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

        void QuadTree::findObjects(BoundingBox *boundingBox,
                std::vector<BoundedObject*> *result) const
        {
            if(root)
                root->findObjects(boundingBox, result);
        }
    }
}
