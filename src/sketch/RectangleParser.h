#ifndef JVGS_SKETCH_RECTANGLEPARSER_H
#define JVGS_SKETCH_RECTANGLEPARSER_H

#include "PrimitiveParser.h"

namespace jvgs
{
    namespace sketch
    {
        class RectangleParser: public PrimitiveParser
        {
            private:

            public:
                RectangleParser(Parser *parser);
                virtual ~RectangleParser();

                virtual Primitive *parse(TiXmlElement *element);
        };
    }
}

#endif
