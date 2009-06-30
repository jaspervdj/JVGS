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
                MPathCommandParser(PathDataParser *dataParser);
                virtual ~MPathCommandParser();

                virtual void parse(Path *path, char command,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
