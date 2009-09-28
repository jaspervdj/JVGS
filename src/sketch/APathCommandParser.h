#ifndef JVGS_SKETCH_APATHCOMMANDPARSER_H
#define JVGS_SKETCH_APATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class APathCommandParser: public PathCommandParser
        {
            private:
            public:
                APathCommandParser();
                virtual ~APathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
