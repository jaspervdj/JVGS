#include "RectangleParser.h"
#include "Parser.h"
#include "Rectangle.h"

#include "../tinyxml/tinyxml.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../core/LogManager.h"
using namespace jvgs::core;

namespace jvgs
{
    namespace sketch
    {
        RectangleParser::RectangleParser(Parser *parser):
            PrimitiveParser(parser)
        {
        }

        RectangleParser::~RectangleParser()
        {
        }

        Primitive *RectangleParser::parse(TiXmlElement *element)
        {
            Rectangle *rectangle = new Rectangle();
            
            float x, y, width, height;
            element->QueryFloatAttribute("x", &x); 
            element->QueryFloatAttribute("y", &y); 
            element->QueryFloatAttribute("width", &width); 
            element->QueryFloatAttribute("height", &height); 

            rectangle->setPosition(Vector2D(x,y));
            rectangle->setSize(Vector2D(width,height));

            if(element->Attribute("style"))
                parseStyle(rectangle, element->Attribute("style"));
            if(element->Attribute("transform"))
                parseTransform(rectangle, element->Attribute("transform"));

            return rectangle;
        }
    }
}
