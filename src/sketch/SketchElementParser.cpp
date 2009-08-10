#include "SketchElementParser.h"
#include "TransformParser.h"
#include "SketchElement.h"
#include "Parser.h"

#include "../tinyxml/tinyxml.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        SketchElementParser::SketchElementParser()
        {
        }

        SketchElementParser::~SketchElementParser()
        {
        }

        void SketchElementParser::parseAttributes(SketchElement *sketchElement,
                TiXmlElement *xmlElement) const
        {
            if(xmlElement->Attribute("transform"))
                parseTransform(sketchElement,
                        xmlElement->Attribute("transform"));

            if(xmlElement->Attribute("id"))
                sketchElement->setId(xmlElement->Attribute("id"));
        }

        void SketchElementParser::parseTransform(SketchElement *sketchElement,
                const std::string &data) const
        {
            TransformParser *tranformParser = new TransformParser();
            AffineTransformationMatrix matrix = tranformParser->parse(data);
            sketchElement->setMatrix(matrix);
            delete tranformParser;
        }
    }
}
