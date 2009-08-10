#ifndef JVGS_SKETCH_MPATHCOMMANDPARSER_H
#define JVGS_SKETCH_MPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class MPathCommandParser: public PathCommandParser
        {
            private:
            public:
                MPathCommandParser();
                virtual ~MPathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
