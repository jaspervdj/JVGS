#include "PathParser.h"
#include "Parser.h"
#include "Path.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <sstream>
#include <string>
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        PathParser::PathParser(Parser *parser):
                SketchElementParser(parser)
        {
        }

        PathParser::~PathParser()
        {
        }

        SketchElement *PathParser::parse(SketchElement *parent,
                TiXmlElement *element)
        {
            Path *path = new Path(parent);

            if(element->Attribute("d")) {
                stringstream data(element->Attribute("d"));
                string token;
                while(data >> token)
                    LogManager::getInstance()->message("%s", token.c_str());
            }

            return path;
        }
    }
}
