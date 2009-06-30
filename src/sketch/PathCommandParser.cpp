#include "PathCommandParser.h"

namespace jvgs
{
    namespace sketch
    {
        PathCommandParser::PathCommandParser(PathDataParser *dataParser)
        {
            this->dataParser = dataParser;
        }

        PathCommandParser::~PathCommandParser()
        {
        }

        PathDataParser *PathCommandParser::getDataParser() const
        {
            return dataParser;
        }
    }
}
