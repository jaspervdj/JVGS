#ifndef JVGS_SKETCH_TEXTPARSER_H
#define JVGS_SKETCH_TEXTPARSER_H

#include <string>
#include <vector>

#include "../video/Color.h"

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
                void split(const std::string &str,
                        const std::string &characters,
                        std::vector<std::string> &destination) const;
                void replaceAll(std::string &text, const std::string &from,
                        const std::string &to) const;
                video::Color parseColor(const std::string &str) const;
        };
    }
}

#endif
