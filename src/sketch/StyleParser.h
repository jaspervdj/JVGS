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

                virtual bool hasValue(const std::string &key);
                virtual std::string getValue(const std::string &key);
                virtual float getValueAsFloat(const std::string &key);
                virtual video::Color getValueAsColor(const std::string &key);
        };
    }
}

#endif
