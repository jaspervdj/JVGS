#ifndef JVGS_SKETCH_PATHPARSER_H
#define JVGS_SKETCH_PATHPARSER_H

#include "SketchElementParser.h"
#include <string>

namespace jvgs
{
    namespace sketch
    {
        class Path;

        class PathParser: public SketchElementParser
        {
            private:
            public:
                const static std::string COMMANDS;

                PathParser(Parser *parser);
                virtual ~PathParser();

                virtual void command(Path *path, const std::string &data);

                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element);
        };
    }
}

#endif
