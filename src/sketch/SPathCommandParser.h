#ifndef JVGS_SKETCH_SPATHCOMMANDPARSER_H
#define JVGS_SKETCH_SPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class SPathCommandParser: public PathCommandParser
        {
            private:
            public:
                SPathCommandParser();
                virtual ~SPathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
