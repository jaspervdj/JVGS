#include "GroupParser.h"
#include "Parser.h"
#include "Group.h"
#include "SketchElement.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        GroupParser::GroupParser()
        {
        }

        GroupParser::~GroupParser()
        {
        }

        SketchElement *GroupParser::parse(SketchElement *parent,
                TiXmlElement *element)
        {

            Group *group = new Group(parent);
            parseAttributes(group, element);

            /* Recurse on children. */
            TiXmlElement *child = element->FirstChildElement();

            while (child) {

                string value = child->ValueStr();
                SketchElementParser *sketchElementParser =
                        Parser::getSketchElementParser(value);

                if (sketchElementParser) {
                    SketchElement *sketchElement =
                            sketchElementParser->parse(group, child);
                    group->addSketchElement(sketchElement);
                }

                child = child->NextSiblingElement();
            }

            return group;
        }
    }
}
