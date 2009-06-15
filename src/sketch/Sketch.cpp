#include "Sketch.h"
#include "Parser.h"
#include "Primitive.h"
#include "PrimitiveRenderer.h"
#include "Group.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

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

            Parser *parser = new Parser(fileName, this);
            parser->parse();
            delete parser;
        }

        Sketch::~Sketch()
        {
            if(root)
                delete root;
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
                LogManager::getInstance()->warning("You are setting the root for a sketch that already has a root!");
            this->root = root;
        }

        Group *Sketch::getRoot() const
        {
            return root;
        }

        void Sketch::render() const
        {
            PrimitiveRenderer *renderer = root->createPrimitiveRenderer();
            renderer->render();
            delete renderer;
        }
    }
}
