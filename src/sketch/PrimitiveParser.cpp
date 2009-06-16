#include "PrimitiveParser.h"
#include "StyleParser.h"
#include "TransformParser.h"
#include "Primitive.h"
#include "Parser.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/AffineTransformationMatrix.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        PrimitiveParser::PrimitiveParser(Parser *parser)
        {
            this->parser = parser;
        }

        PrimitiveParser::~PrimitiveParser()
        {
        }

        Parser *PrimitiveParser::getParser() const
        {
            return parser;
        }

        void PrimitiveParser::parseStyle(Primitive *primitive,
                const string &data)
        {
            StyleParser *styleParser = new StyleParser(data);
            
            if(styleParser->getValue("fill") == "none") {
                primitive->setFill(false);
            } else {
                primitive->setFill(true);
                primitive->setFillColor(styleParser->getValueAsColor("fill"));
            }

            if(styleParser->getValue("stroke") == "none") {
                primitive->setStroke(false);
            } else {
                primitive->setStroke(true);
                primitive->setStrokeColor(
                        styleParser->getValueAsColor("stroke"));
            }

            delete styleParser;
        }

        void PrimitiveParser::parseTransform(Primitive *primitive,
                const std::string &data)
        {
            TransformParser *tranformParser = new TransformParser();
            AffineTransformationMatrix matrix = tranformParser->parse(data);
            primitive->setMatrix(matrix);
            delete tranformParser;
        }
    }
}
