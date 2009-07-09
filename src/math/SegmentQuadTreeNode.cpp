#include "SegmentQuadTreeNode.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

namespace jvgs
{
    namespace math
    {
        SegmentQuadTreeNode::SegmentQuadTreeNode(const BoundingBox &boundingBox)
        {
            children = 0;
            this->boundingBox = boundingBox;
        }

        SegmentQuadTreeNode::~SegmentQuadTreeNode()
        {
            if(children) {
                for(int i = 0; i < 4; i++)
                    delete children[i];
                delete[] children;
            }
        }

        const BoundingBox &SegmentQuadTreeNode::getBoundingBox() const
        {
            return boundingBox;
        }

        void SegmentQuadTreeNode::addSegment(LineSegment *segment)
        {
            segments.push_back(segment);
        }

        void SegmentQuadTreeNode::subdivide()
        {
            /* Error. */
            if(children) {
                LogManager::getInstance()->error(
                        "Subdividing already subdivided SegmentQuadTreeNode.");
            }

            children = new SegmentQuadTreeNode *[4];

            Vector2D size = (boundingBox.getBottomRight() -
                    boundingBox.getTopLeft()) * 0.5f;

            /* Top left. */
            children[0] = new SegmentQuadTreeNode(BoundingBox(
                    boundingBox.getTopLeft(),
                    boundingBox.getTopLeft() + size));

            /* Bottom left. */
            children[1] = new SegmentQuadTreeNode(BoundingBox(
                    boundingBox.getTopLeft() + size.onlyY(),
                    boundingBox.getTopLeft() + size.onlyY() + size));

            /* Bottom right. */
            children[2] = new SegmentQuadTreeNode(BoundingBox(
                    boundingBox.getTopLeft() + size,
                    boundingBox.getBottomRight()));

            /* Top right. */
            children[3] = new SegmentQuadTreeNode(BoundingBox(
                    boundingBox.getTopLeft() + size.onlyY(),
                    boundingBox.getTopLeft() + size.onlyY() + size));

            /* Clear contents. */
            vector<LineSegment*> original = segments;
            segments.clear();

            for(vector<LineSegment*>::iterator iterator = original.begin();
                    iterator != original.end(); iterator++) {
                LineSegment *segment = *iterator;
                bool added = false;
                for(int i = 0; i < 4; i++) {
                    /* Goes completely in it - added. */
                    if(segment->getBoundingBox()->completelyIn(
                            children[i]->getBoundingBox())) {
                        children[i]->addSegment(segment);
                        added = true;
                    }
                }

                /* Not added, add to root here. */
                addSegment(segment);
            }
        }
    }
}
