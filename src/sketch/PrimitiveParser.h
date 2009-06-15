#ifndef JVGS_SKETCH_PRIMITIVEPARSER_H
#define JVGS_SKETCH_PRIMITIVEPARSER_H

#include <string>

class TiXmlElement;

namespace jvgs
{
    namespace sketch
    {
        class Primitive;
        class Parser;

        class PrimitiveParser
        {
            private:
                Parser *parser;

            public:
                PrimitiveParser(Parser *parser);
                virtual ~PrimitiveParser();

                virtual Parser *getParser() const;

                virtual void parseStyle(Primitive *primitive, const std::string &data);
                virtual void parseTransform(Primitive *primitive, const std::string &data);
                virtual Primitive *parse(Primitive *parent,
                        TiXmlElement *element) = 0;
        };
    }
}

#endif
