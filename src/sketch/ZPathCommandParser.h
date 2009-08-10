#ifndef JVGS_SKETCH_ZPATHCOMMANDPARSER_H
#define JVGS_SKETCH_ZPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class ZPathCommandParser: public PathCommandParser
        {
            private:
            public:
                ZPathCommandParser();
                virtual ~ZPathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
