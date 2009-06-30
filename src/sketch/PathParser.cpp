#include "PathParser.h"
#include "Parser.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
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

            if(element->Attribute("transform"))
                parseTransform(path, element->Attribute("transform"));

            string data =
                    element->Attribute("d") ? element->Attribute("d") : "";

            PathDataParser *pathDataParser = new PathDataParser(path, data);
            pathDataParser->parse();
            delete pathDataParser;

            return path;
        }
    }
}
