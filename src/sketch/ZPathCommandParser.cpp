#include "ZPathCommandParser.h"
#include "LPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        ZPathCommandParser::ZPathCommandParser()
        {
        }

        ZPathCommandParser::~ZPathCommandParser()
        {
        }

        void ZPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            LPathCommandParser *lCommandParser = new LPathCommandParser();

            vector<float> lArguments;
            lArguments.push_back(dataParser->getCurrentPoint().getX());
            lArguments.push_back(dataParser->getCurrentPoint().getY());
            lCommandParser->parse(path, 'L', dataParser, lArguments);

            delete lCommandParser;
        }
    }
}
