#ifndef JVGS_SKETCH_TRANSFORMPARSER_H
#define JVGS_SKETCH_TRANSFORMPARSER_H

#include <string>
#include <map>
#include "../math/AffineTransformationMatrix.h"
#include "TextParser.h"

namespace jvgs
{
    namespace sketch
    {
        class TransformCommand;

        class TransformParser: public TextParser
        {
            private:
                std::map<std::string, TransformCommand*> commands;

            public:
                TransformParser();
                virtual ~TransformParser();

                math::AffineTransformationMatrix parse(const std::string &data);
        };
    }
}

#endif
