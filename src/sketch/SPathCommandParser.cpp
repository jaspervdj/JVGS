#include "SPathCommandParser.h"
#include "CPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/CubicCurve.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        SPathCommandParser::SPathCommandParser(PathDataParser *dataParser):
                PathCommandParser(dataParser)
        {
        }

        SPathCommandParser::~SPathCommandParser()
        {
        }

        void SPathCommandParser::parse(Path *path, char command,
                const vector<float> &arguments) const
        {
            PathDataParser *dataParser = getDataParser();

            CPathCommandParser *cCommandParser =
                    new CPathCommandParser(dataParser);

            for(int i = 0; i < arguments.size(); i += 4) {

                Vector2D control1 = dataParser->getCurrentPoint().reflect(
                        dataParser->getLastControlPoint());

                if(dataParser->isRelativeCommand(command))
                    control1 -= dataParser->getCurrentPoint();

                vector<float> cArguments;

                cArguments.push_back(control1.getX());
                cArguments.push_back(control1.getY());
                for(int j = 0; j < 4; j++)
                    cArguments.push_back(arguments[i + j]);

                char cCommand = dataParser->isRelativeCommand(command) ?
                        'c' : 'C';

                cCommandParser->parse(path, cCommand, cArguments);
            }

            delete cCommandParser;
        }
    }
}
