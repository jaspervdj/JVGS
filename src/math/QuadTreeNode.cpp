#include "QuadTreeNode.h"
#include "QuadTree.h"
#include "LineSegment.h"
#include "BoundingBox.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

namespace jvgs
{
    namespace math
    {
        QuadTreeNode::QuadTreeNode(QuadTree *tree, BoundingBox *boundingBox)
        {
            this->tree = tree;
            children = 0;
            this->boundingBox = boundingBox;
        }

        QuadTreeNode::~QuadTreeNode()
        {
            if(children) {
                for(int i = 0; i < 4; i++)
                    delete children[i];
                delete[] children;
            }

            delete boundingBox;
        }

        BoundingBox *QuadTreeNode::getBoundingBox() const
        {
            return boundingBox;
        }

        void QuadTreeNode::addObject(BoundedObject *object)
        {
            /* Children, try to add to them. */
            if(children) {
                bool added = false;
                for(int i = 0; i < 4; i++) {
                    /* Goes completely in it - added. */
                    if(object->getBoundingBox()->completelyIn(
                            children[i]->getBoundingBox())) {
                        children[i]->addObject(object);
                        added = true;
                    } 
                }

                /* Not added, add to root here. */
                if(!added)
                    objects.push_back(object);

            /* Add to root and maybe subdidivde. */
            } else {
                objects.push_back(object);
                if(objects.size() >= (vector<BoundedObject*>::size_type)
                        tree->getSubdivideLimit())
                    subdivide();
            }
        }

        void QuadTreeNode::subdivide()
        {
            /* Error. */
            if(children) {
                LogManager::getInstance()->error(
                        "Subdividing already subdivided QuadTreeNode.");
            }

            children = new QuadTreeNode *[4];

            Vector2D size = (boundingBox->getBottomRight() -
                    boundingBox->getTopLeft()) * 0.5f;

            /* Top left. */
            children[0] = new QuadTreeNode(tree, new BoundingBox(
                    boundingBox->getTopLeft(),
                    boundingBox->getTopLeft() + size));

            /* Bottom left. */
            children[1] = new QuadTreeNode(tree, new BoundingBox(
                    boundingBox->getTopLeft() + size.onlyY(),
                    boundingBox->getTopLeft() + size.onlyY() + size));

            /* Bottom right. */
            children[2] = new QuadTreeNode(tree, new BoundingBox(
                    boundingBox->getTopLeft() + size,
                    boundingBox->getBottomRight()));

            /* Top right. */
            children[3] = new QuadTreeNode(tree, new BoundingBox(
                    boundingBox->getTopLeft() + size.onlyX(),
                    boundingBox->getTopLeft() + size.onlyX() + size));

            /* Clear contents. */
            vector<BoundedObject*> original = objects;
            objects.clear();

            for(vector<BoundedObject*>::iterator iterator = original.begin();
                    iterator != original.end(); iterator++) {
                /* Will add it to the correct child. */
                addObject(*iterator);
            }
        }

        void QuadTreeNode::findObjects(BoundingBox *boundingBox,
                std::vector<BoundedObject*> *result)
        {
            /* Add all objects. */
            for(vector<BoundedObject*>::iterator iterator = objects.begin();
                    iterator != objects.end(); iterator++) {
                if((*iterator)->getBoundingBox()->intersectsWith(boundingBox))
                    result->push_back(*iterator);
            }

            /* Check children. */
            if(children) {
                for(int i = 0; i < 4; i++) {
                    if(boundingBox->intersectsWith(
                            children[i]->getBoundingBox())) {
                        children[i]->findObjects(boundingBox, result);
                    }
                }
            }
        }
    }
}
