#ifndef JVGS_SKETCH_RECTANGLEPARSER_H
#define JVGS_SKETCH_RECTANGLEPARSER_H

#include "SketchElementParser.h"

namespace jvgs
{
    namespace sketch
    {
        class RectangleParser: public SketchElementParser
        {
            private:

            public:
                RectangleParser(Parser *parser);
                virtual ~RectangleParser();

                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element);
        };
    }
}

#endif
