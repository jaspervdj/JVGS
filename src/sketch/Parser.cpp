#include "Parser.h"
#include "Sketch.h"
#include "PrimitiveParser.h"
#include "GroupParser.h"
#include "RectangleParser.h"
#include "StyleMap.h"
#include "Group.h"

using namespace std;

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace sketch
    {
        Parser::Parser(string fileName, Sketch *sketch)
        {
            document = new TiXmlDocument( fileName.c_str() );
            if (!document->LoadFile()) {
                LogManager::getInstance()->error(
                        "Could not load xml document: %s", fileName.c_str());
            }

            this->sketch = sketch;

            primitiveParsers["rect"] = new RectangleParser(this);
            primitiveParsers["g"] = new GroupParser(this);
        }

        Parser::~Parser()
        {
            for( map<string,PrimitiveParser*>::iterator iterator =
                    primitiveParsers.begin();
                    iterator != primitiveParsers.end(); iterator++ ) {
                delete iterator->second;
            }

            delete document;
        }

        PrimitiveParser *Parser::getPrimitiveParser(string tag)
        {

            map<string, PrimitiveParser*>::iterator iterator =
                    primitiveParsers.find(tag);
            if (iterator != primitiveParsers.end())
                return iterator->second;
            else
                return 0;
        }

        void Parser::parse()
        {
            TiXmlElement *rootElement = document->RootElement();

            float width, height;
            rootElement->QueryFloatAttribute("width", &width);
            rootElement->QueryFloatAttribute("height", &height);
            sketch->setSize(Vector2D(width, height));

            GroupParser *groupParser = new GroupParser(this);

            Group *root = (Group*) groupParser->parse(0, rootElement);
            sketch->setRoot(root);

            /* Set a number of defaults. */
            StyleMap *styleMap = root->getStyleMap();
            styleMap->load(string("opacity:1; stroke-opacity:1;") +
                    "fill-opacity:1;");

            delete groupParser;
        }
    };
};
