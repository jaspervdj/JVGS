#ifndef JVGS_SKETCH_PATHPARSER_H
#define JVGS_SKETCH_PATHPARSER_H

#include "SketchElementParser.h"

namespace jvgs
{
    namespace sketch
    {
        class PathParser: public SketchElementParser
        {
            private:
            public:
                PathParser(Parser *parser);
                virtual ~PathParser();

                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element);
        };
    }
}

#endif
