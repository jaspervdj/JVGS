#ifndef JVGS_SKETCH_QPATHCOMMANDPARSER_H
#define JVGS_SKETCH_QPATHCOMMANDPARSER_H

#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        class QPathCommandParser: public PathCommandParser
        {
            private:
            public:
                QPathCommandParser();
                virtual ~QPathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const;
        };
    }
}

#endif
