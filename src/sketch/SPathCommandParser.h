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
                SPathCommandParser(PathDataParser *dataParser);
                virtual ~SPathCommandParser();

                virtual void parse(Path *path, char command,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
