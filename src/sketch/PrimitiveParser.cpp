#include "PrimitiveParser.h"
#include "StyleMap.h"
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
