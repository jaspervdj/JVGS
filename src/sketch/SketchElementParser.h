#ifndef JVGS_SKETCH_SKETCHELEMENTPARSER_H
#define JVGS_SKETCH_SKETCHELEMENTPARSER_H

#include "TextParser.h"
#include <string>

class TiXmlElement;

namespace jvgs
{
    namespace sketch
    {
        class SketchElement;
        class Parser;

        class SketchElementParser: public TextParser
        {
            private:
                Parser *parser;

            public:
                SketchElementParser(Parser *parser);
                virtual ~SketchElementParser();

                virtual Parser *getParser() const;

                virtual void parseTransform(SketchElement *sketchElement,
                        const std::string &data);

                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element) = 0;
        };
    }
}

#endif
