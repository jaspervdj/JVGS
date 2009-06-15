#ifndef JVGS_SKETCH_TEXTPARSER_H
#define JVGS_SKETCH_TEXTPARSER_H

#include <string>
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class TextParser
        {
            private:
            public:
                TextParser();
                virtual ~TextParser();

                std::string trim(const std::string &str) const;
                void split(const std::string &str, char c,
                        std::vector<std::string> &destination) const;
        };
    }
}

#endif
