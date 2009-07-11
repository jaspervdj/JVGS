#include "SegmentQuadTree.h"
#include "SegmentQuadTreeNode.h"
#include "LineSegment.h"
#include "Vector2D.h"

using namespace std;

namespace jvgs
{
    namespace math
    {
        SegmentQuadTree::SegmentQuadTree(vector<LineSegment*> *segments)
        {
            /* Initialize bounding box. */
            Vector2D topLeft, bottomRight;
            vector<LineSegment*>::iterator iterator = segments->begin();
            topLeft = (*iterator)->getBoundingBox()->getTopLeft();
            bottomRight = (*iterator)->getBoundingBox()->getBottomRight();
            
            /* Expand bounding box. */
            for(iterator++; iterator != segments->end(); iterator++) {
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

            root = new SegmentQuadTreeNode(BoundingBox(topLeft, bottomRight));
            for(iterator = segments->begin(); iterator != segments->end();
                    iterator++) {
                root->addSegment(*iterator);
            }
        }

        SegmentQuadTree::~SegmentQuadTree()
        {
            delete root;
        }

        void SegmentQuadTree::findSegments(BoundingBox *boundingBox,
                std::vector<LineSegment*> *result) const
        {
            root->findSegments(boundingBox, result);
        }
    }
}
