#ifndef JVGS_SKETCH_PATHCOMMANDPARSER_H
#define JVGS_SKETCH_PATHCOMMANDPARSER_H

#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class PathDataParser;
        class Path;

        class PathCommandParser
        {
            public:
                PathCommandParser();
                virtual ~PathCommandParser();

                virtual void parse(Path *path, char command,
                        PathDataParser *dataParser,
                        const std::vector<float> &arguments) const = 0;
        };
    }
}

#endif
