#include "Parser.h"

#include <iostream>
using namespace std;

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

#include "Sketch.h"
#include "PrimitiveParser.h"
#include "GroupParser.h"
#include "RectangleParser.h"

namespace jvgs
{
    namespace sketch
    {
        Parser::Parser(string fileName, Sketch *sketch)
        {
            document = new TiXmlDocument( fileName.c_str() );
            if (!document->LoadFile()) {
                LogManager::getInstance()->error("Could not load xml document: %s",
                        fileName.c_str());
            }

            this->sketch = sketch;

            primitiveParsers["rect"] = new RectangleParser(this);
            primitiveParsers["g"] = new GroupParser(this);
        }

        Parser::~Parser()
        {
            map<string,PrimitiveParser*>::iterator iterator = primitiveParsers.begin();
            while (iterator != primitiveParsers.end()) {
                delete iterator->second;
                iterator++;
            }

            delete document;
        }

        PrimitiveParser *Parser::getPrimitiveParser(string tag)
        {

            map<string, PrimitiveParser*>::iterator iterator = primitiveParsers.find(tag);
            if (iterator != primitiveParsers.end())
                return iterator->second;
            else
                return 0;
        }

        void Parser::parse()
        {
            TiXmlElement *root = document->RootElement();

            float width, height;
            root->QueryFloatAttribute("width", &width);
            root->QueryFloatAttribute("height", &height);
            sketch->setSize(Vector2D(width, height));
            LogManager::getInstance()->message("Loaded file, size: (%f, %f).", width, height);

            GroupParser *groupParser = new GroupParser(this);
            sketch->setRoot((Group*)groupParser->parse(root));
            delete groupParser;
        }
    };
};
