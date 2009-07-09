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

        /** A parser that parses one xml element of a svg file.
         */
        class SketchElementParser: public TextParser
        {
            private:
                /** Reference to the main parser. */
                Parser *parser;

            public:
                /** Constructor.
                 *  @param parser Reference to the main parser.
                 */
                SketchElementParser(Parser *parser);

                /** Destructor.
                 */
                virtual ~SketchElementParser();

                /** Get a reference to the main parser.
                 *  @return A reference to the main parser.
                 */
                virtual Parser *getParser() const;

                /** Parse a number of general attributes and apply them
                 *  to the sketch element.
                 *  @param sketchElement SketchElement to apply to.
                 *  @param xmlElement XML element to get the attributes from.
                 */
                virtual void parseAttributes(SketchElement *sketchElement,
                        TiXmlElement *xmlElement) const;

                /** Parse and create the element.
                 *  @param parent The parent of the new SketchElement.
                 *  @param element XML element to load the SketchElement from.
                 *  @return The new SketchElement.
                 */
                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element) = 0;

            protected:
                /** Parse a transform="..." attribute for a certain
                 *  SketchElement.
                 *  @param sketchElement The SketchElement to parse the
                 *         transform tag for.
                 *  @param data The data in the transform attribute.
                 */
                virtual void parseTransform(SketchElement *sketchElement,
                        const std::string &data) const;

        };
    }
}

#endif
