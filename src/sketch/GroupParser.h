#ifndef JVGS_SKETCH_GROUPPARSER_H
#define JVGS_SKETCH_GROUPPARSER_H

#include "PrimitiveParser.h"

namespace jvgs
{
    namespace sketch
    {
        class GroupParser: public PrimitiveParser
        {
            private:
            public:
                GroupParser(Parser *parser);
                virtual ~GroupParser();

                virtual Primitive *parse(Primitive *parser,
                        TiXmlElement *element);
        };
    }
}

#endif
