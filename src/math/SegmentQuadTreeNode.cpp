#include "SegmentQuadTreeNode.h"
#include "LineSegment.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <iostream>
#include <string>
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
            /* Children, try to add to them. */
            if(children) {
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
                if(!added)
                    segments.push_back(segment);

            /* Add to root and maybe subdidivde. */
            } else {
                segments.push_back(segment);
                if(segments.size() >=
                        (vector<LineSegment*>::size_type) SUBDIVIDE_LIMIT)
                    subdivide();
            }
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
                    boundingBox.getTopLeft() + size.onlyX(),
                    boundingBox.getTopLeft() + size.onlyX() + size));

            /* Clear contents. */
            vector<LineSegment*> original = segments;
            segments.clear();

            for(vector<LineSegment*>::iterator iterator = original.begin();
                    iterator != original.end(); iterator++) {
                /* Will add it to the correct child. */
                addSegment(*iterator);
            }
        }

        void SegmentQuadTreeNode::findSegments(BoundingBox *boundingBox,
                std::vector<LineSegment*> *result)
        {
            /* Add all segments. */
            for(vector<LineSegment*>::iterator iterator = segments.begin();
                    iterator != segments.end(); iterator++) {
                if((*iterator)->getBoundingBox()->intersectsWith(*boundingBox))
                    result->push_back(*iterator);
            }

            /* Check children. */
            if(children) {
                for(int i = 0; i < 4; i++) {
                    if(boundingBox->intersectsWith(
                            children[i]->getBoundingBox())) {
                        children[i]->findSegments(boundingBox, result);
                    }
                }
            }
        }
    }
}
