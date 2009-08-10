#ifndef JVGS_SKETCH_TPATHCOMMANDPARSER_H
#define JVGS_SKETCH_TPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class TPathCommandParser: public PathCommandParser
        {
            private:
            public:
                TPathCommandParser();
                virtual ~TPathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
