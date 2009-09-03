#include "Sketch.h"
#include "Parser.h"
#include "SketchElement.h"
#include "SketchElementRenderer.h"
#include "Group.h"
#include "Path.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../video/Renderer.h"
#include "../video/VideoManager.h"
using namespace jvgs::video;

using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        Sketch::Sketch(const string &fileName)
        {
            this->fileName = fileName;
            size = Vector2D();
            root = 0;

            /* Parse in everything. */
            Parser *parser = new Parser(fileName, this);
            parser->parse();
            delete parser;
        }

        Sketch::Sketch(const Vector2D &size)
        {
            this->fileName = "not loaded from file";
            this->size = size;
            root = 0;
        }

        Sketch::~Sketch()
        {
            if(root)
                delete root;
            if(tree)
                delete tree;
        }

        const string &Sketch::getFileName() const
        {
            return fileName;
        }

        void Sketch::setSize(const Vector2D &size)
        {
            this->size = size;
        }

        const Vector2D &Sketch::getSize() const
        {
            return size;
        }

        void Sketch::setRoot(Group *root)
        {
            if(this->root)
                LogManager::getInstance()->warning(
                        "Setting root for a sketch that already has a root!");
            this->root = root;
        }

        Group *Sketch::getRoot() const
        {
            return root;
        }

        SketchElement *Sketch::getElementById(const string &id)
        {
            map<string, SketchElement*>::iterator result = ids.find(id);
            if(result != ids.end())
                return result->second;
            else
                return 0;
        }

        void Sketch::finnish()
        {
            root->finnish();

            processElements(root);
            tree = new QuadTree(&boundedObjects, 100);
        }

        void Sketch::render() const
        {
            root->render();
        }

        void Sketch::render(BoundingBox *boundingBox)
        {
            vector<BoundedObject*> result;
            tree->findObjects(boundingBox, &result);
            for(vector<BoundedObject*>::iterator iterator = result.begin();
                    iterator != result.end(); iterator++) {
                Path *path = (Path*) *iterator;
                path->render();
            }
        }

        void Sketch::processElements(Group *group)
        {
            /* For all sketch elements in this group. */
            for(int i = 0; i < group->getNumberOfSketchElements(); i++) {
                SketchElement *element = group->getSketchElement(i);

                /* Set the id. */
                ids[element->getId()] = element;

                /* Add to the objects list. */
                if(element->getType() == SKETCHELEMENTTYPE_PATH)
                    boundedObjects.push_back((Path*) element);

                /* Recurse if we are dealing with a group. */
                if(element->getType() == SKETCHELEMENTTYPE_GROUP)
                    processElements((Group*) element);
            }
        }
    }
}
