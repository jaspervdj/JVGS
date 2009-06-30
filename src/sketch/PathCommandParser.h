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
            private:
                PathDataParser *dataParser;

            public:
                PathCommandParser(PathDataParser *dataParser);
                virtual ~PathCommandParser();

                PathDataParser *getDataParser() const;

                virtual void parse(Path *path, char command,
                        const std::vector<float> &arguments) const = 0;
        };
    }
}

#endif
