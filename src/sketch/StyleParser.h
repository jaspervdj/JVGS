#ifndef JVGS_SKETCH_STYLEPARSER_H
#define JVGS_SKETCH_STYLEPARSER_H

#include <istream>
#include <string>
#include <map>
#include "../video/Color.h"
#include "TextParser.h"

namespace jvgs
{
    namespace sketch
    {
        class StyleParser: public TextParser
        {
            private:
                std::istream *in;
                std::map<std::string,std::string> values;

            public:
                StyleParser(const std::string &data);
                virtual ~StyleParser();

                virtual std::string getValue(const std::string &key);

                video::Color parseColor(const std::string &value);
        };
    }
}

#endif
