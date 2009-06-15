#ifndef JVGS_SKETCH_PARSER_H
#define JVGS_SKETCH_PARSER_H

#include <map>
#include <string>
class TiXmlDocument;
class TiXmlElement;

namespace jvgs
{
    namespace sketch
    {
        class PrimitiveParser;
        class Sketch;

        class Parser
        {
            private:
                Sketch *sketch;
                TiXmlDocument *document;
                std::map<std::string,PrimitiveParser*> primitiveParsers;

            public:
                /** Constructor.
                 *  @param fileName Filename of the svg file.
                 *  @param sketch Sketch object to be filled in.
                 */
                Parser(std::string fileName, Sketch *sketch);
                virtual ~Parser();

                PrimitiveParser *getPrimitiveParser(std::string tag);

                void parse();
        };
    };
};

#endif
