#include "PathParser.h"
#include "Parser.h"
#include "Path.h"
#include "PathSegment.h"
#include "StyleMap.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        const string PathParser::COMMANDS = "MmLlHhVvCcSsQqTtAaZz";

        PathParser::PathParser(Parser *parser):
                SketchElementParser(parser)
        {
        }

        PathParser::~PathParser()
        {
        }

        void PathParser::command(Path *path, const string &data)
        {
            char command = data[0];
            vector<string> splitted;
            vector<float> arguments;
            split(data.substr(1), ", ", splitted);
            for(vector<string>::iterator iterator = splitted.begin();
                    iterator != splitted.end(); iterator++) {
                stringstream converter(*iterator);
                float f;
                converter >> f;
                arguments.push_back(f);
            }

            path->addSegment(new PathSegment(command, arguments));
        }

        SketchElement *PathParser::parse(SketchElement *parent,
                TiXmlElement *element)
        {
            Path *path = new Path(parent);

            string data =
                    element->Attribute("d") ? element->Attribute("d") : "";

            string::size_type start = data.find_first_of(COMMANDS);
            if(start == string::npos)
                start = 0;

            string::size_type end = data.find_first_of(COMMANDS, start + 1);

            while(end != string::npos) {
                command(path, data.substr(start, end - start));
                start = end;
                end = data.find_first_of(COMMANDS, start + 1);
            }

            /* Add last command. */
            command(path, data.substr(start));

            if(element->Attribute("style"))
                path->getStyleMap()->load(element->Attribute("style"));
            if(element->Attribute("transform"))
                parseTransform(path, element->Attribute("transform"));

            return path;
        }
    }
}
