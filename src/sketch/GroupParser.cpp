#include "GroupParser.h"
#include "Parser.h"
#include "Group.h"
#include "SketchElement.h"
#include "StyleMap.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        GroupParser::GroupParser(Parser *parser): SketchElementParser(parser)
        {
        }

        GroupParser::~GroupParser()
        {
        }

        SketchElement *GroupParser::parse(SketchElement *parent,
                TiXmlElement *element)
        {

            Group *group = new Group(parent);

            if( element->Attribute("style") ) {
                StyleMap *styleMap = group->getStyleMap();
                styleMap->load(element->Attribute("style"));
            }

            if(element->Attribute("transform"))
                parseTransform(group, element->Attribute("transform"));

            /* Recurse on children. */
            TiXmlElement *child = element->FirstChildElement();

            while (child) {

                string value = child->ValueStr();
                SketchElementParser *sketchElementParser =
                        getParser()->getSketchElementParser(value);

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
