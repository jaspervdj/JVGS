#ifndef JVGS_SKETCH_LPATHCOMMANDPARSER_H
#define JVGS_SKETCH_LPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class LPathCommandParser: public PathCommandParser
        {
            private:
            public:
                LPathCommandParser(PathDataParser *dataParser);
                virtual ~LPathCommandParser();

                virtual void parse(Path *path, char command,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
