#ifndef JVGS_SKETCH_PATHDATAPARSER_H
#define JVGS_SKETCH_PATHDATAPARSER_H

#include "TextParser.h"
#include <string>

namespace jvgs
{
    namespace sketch
    {
        class Path;

        class PathDataParser: public TextParser
        {
            private:
                Path *path;
                std::string data;
            public:
                const static std::string COMMANDS;

                PathDataParser(Path *path, const std::string &data);
                virtual ~PathDataParser();

                virtual void parse();
                virtual void command(const std::string &commandData);
        };
    }
}

#endif
