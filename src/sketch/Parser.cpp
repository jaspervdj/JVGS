#include "Parser.h"
#include "Sketch.h"
#include "SketchElementParser.h"
#include "GroupParser.h"
#include "PathParser.h"
#include "Group.h"

using namespace std;

#include "../core/LogManager.h"
#include "../core/DataManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace sketch
    {
        /* Map filling. */
        map<string, SketchElementParser*> createSketchElementParsers()
        {
            map<string, SketchElementParser*> sketchElementParsers;

            static GroupParser groupParser;
            sketchElementParsers["g"] = &groupParser;

            static PathParser pathParser;
            sketchElementParsers["path"] = &pathParser;

            return sketchElementParsers;
        }

        /* Map implementation. */
        map<string, SketchElementParser*> Parser::sketchElementParsers = 
                createSketchElementParsers();

        Parser::Parser(string fileName, Sketch *sketch)
        {
            DataManager *dataManager = DataManager::getInstance();

            document = new TiXmlDocument(dataManager->expand(fileName));
            if(!document->LoadFile()) {
                LogManager::getInstance()->error(
                        "Could not load xml document: %s", fileName.c_str());
            }

            this->sketch = sketch;
        }

        Parser::~Parser()
        {
            delete document;
        }

        void Parser::parse()
        {
            TiXmlElement *rootElement = document->RootElement();

            float width, height;
            rootElement->QueryFloatAttribute("width", &width);
            rootElement->QueryFloatAttribute("height", &height);
            sketch->setSize(Vector2D(width, height));

            GroupParser *groupParser = new GroupParser();

            Group *root = (Group*) groupParser->parse(0, rootElement);
            sketch->setRoot(root);
            sketch->finnish();

            delete groupParser;
        }

        SketchElementParser *Parser::getSketchElementParser(const string &tag)
        {
            map<string, SketchElementParser*>::iterator iterator =
                    sketchElementParsers.find(tag);
            if (iterator != sketchElementParsers.end())
                return iterator->second;
            else
                return 0;
        }
    };
};
