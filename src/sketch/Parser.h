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

        /** Class to parse a complete svg file into a Sketch.
         */
        class Parser
        {
            private:
                /** Sketch to be filled in. */
                Sketch *sketch;

                /** XML document to be loaded. */
                TiXmlDocument *document;

                /** Map containing the different svg element parsers. */
                std::map<std::string,SketchElementParser*> sketchElementParsers;

            public:
                /** Constructor.
                 *  @param fileName Filename of the svg file.
                 *  @param sketch Sketch object to be filled in.
                 */
                Parser(std::string fileName, Sketch *sketch);

                /** Destructor.
                 */
                virtual ~Parser();

                /** Get an appropriate SketchElementParser for a certain xml
                 *  tag.
                 *  @param tag Tag to find a SketchElementParser for.
                 *  @return An appropriate SketchElementParser.
                 */
                SketchElementParser *getSketchElementParser(
                    const std::string &tag);

                /** Start parsing, load everything.
                 */
                void parse();
        };
    };
};

#endif
