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
        class SketchElementParser;
        class Sketch;

        class Parser
        {
            private:
                Sketch *sketch;
                TiXmlDocument *document;
                std::map<std::string,SketchElementParser*> sketchElementParsers;

            public:
                /** Constructor.
                 *  @param fileName Filename of the svg file.
                 *  @param sketch Sketch object to be filled in.
                 */
                Parser(std::string fileName, Sketch *sketch);
                virtual ~Parser();

                SketchElementParser *getSketchElementParser(std::string tag);

                void parse();
        };
    };
};

#endif
