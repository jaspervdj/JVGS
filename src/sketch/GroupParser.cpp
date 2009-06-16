#include "GroupParser.h"
#include "Parser.h"
#include "Group.h"
#include "Primitive.h"
#include "StyleMap.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        GroupParser::GroupParser(Parser *parser): PrimitiveParser(parser)
        {
        }

        GroupParser::~GroupParser()
        {
        }

        Primitive *GroupParser::parse(Primitive *parent, TiXmlElement *element)
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
                PrimitiveParser *primitiveParser =
                        getParser()->getPrimitiveParser(value);

                if (primitiveParser) {
                    Primitive *primitive = primitiveParser->parse(group, child);
                    group->addPrimitive(primitive);
                }

                child = child->NextSiblingElement();
            }

            return group;
        }
    }
}
