#ifndef JVGS_SKETCH_CPATHCOMMANDPARSER_H
#define JVGS_SKETCH_CPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class CPathCommandParser: public PathCommandParser
        {
            private:
            public:
                CPathCommandParser();
                virtual ~CPathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
