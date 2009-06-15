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

        void PrimitiveParser::parseStyle(Primitive *primitive, const string &data)
        {
            StyleParser *styleParser = new StyleParser(data);
            
            LogManager::getInstance()->message("stroke: %s",
                    styleParser->getValue("stroke").c_str());

            if(styleParser->getValue("fill") == "none") {
                primitive->setFill(false);
            } else {
                primitive->setFill(true);
                string color = styleParser->getValue("fill");
                primitive->setFillColor(styleParser->parseColor(color));
                LogManager::getInstance()->message("Color: %f, %f, %f.",
                                                   primitive->getFillColor().getRed(),
                                                   primitive->getFillColor().getGreen(),
                                                   primitive->getFillColor().getBlue());

            }

            if(styleParser->getValue("stroke") == "none") {
                primitive->setStroke(false);
            } else {
                primitive->setStroke(true);
                string color = styleParser->getValue("stroke");
                primitive->setStrokeColor(styleParser->parseColor(color));
            }

            delete styleParser;
        }

        void PrimitiveParser::parseTransform(Primitive *primitive, const std::string &data)
        {
            TransformParser *tranformParser = new TransformParser();
            AffineTransformationMatrix matrix = tranformParser->parse(data);
            primitive->setMatrix(matrix);
            delete tranformParser;
        }
    }
}
