#ifndef JVGS_SKETCH_STYLEMAP_H
#define JVGS_SKETCH_STYLEMAP_H

#include <istream>
#include <string>
#include <map>
#include "../video/Color.h"
#include "TextParser.h"

namespace jvgs
{
    namespace sketch
    {
        class StyleMap: public TextParser
        {
            private:
                StyleMap *parent;
                std::map<std::string,std::string> values;

            public:
                StyleMap(StyleMap *parent);
                virtual ~StyleMap();

                virtual void load(const std::string &data);
                virtual bool hasValue(const std::string &key);
                virtual void setValue(const std::string &key,
                        const std::string &value);
                virtual std::string getValue(const std::string &key);
                virtual float getValueAsFloat(const std::string &key);
                virtual video::Color getValueAsColor(const std::string &key);
        };
    }
}

#endif
