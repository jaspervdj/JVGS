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
                CPathCommandParser(PathDataParser *dataParser);
                virtual ~CPathCommandParser();

                virtual void parse(Path *path, char command,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
