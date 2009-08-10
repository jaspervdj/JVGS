#ifndef JVGS_SKETCH_GROUPPARSER_H
#define JVGS_SKETCH_GROUPPARSER_H

#include "SketchElementParser.h"

namespace jvgs
{
    namespace sketch
    {
        class GroupParser: public SketchElementParser
        {
            private:
            public:
                GroupParser();
                virtual ~GroupParser();

                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element);
        };
    }
}

#endif
