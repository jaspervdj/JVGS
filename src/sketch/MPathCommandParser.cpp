#include "MPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"
#include "LPathCommandParser.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        MPathCommandParser::MPathCommandParser()
        {
        }

        MPathCommandParser::~MPathCommandParser()
        {
        }

        void MPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            Vector2D translation(arguments[0], arguments[1]);
            translation = dataParser->toAbsoluteSpace(command, translation);

            dataParser->setStartingPoint(translation);
            dataParser->setCurrentPoint(translation);
            dataParser->setLastControlPoint(translation);

            PathComponent *component = new PathComponent(path);
            path->addComponent(component);
            dataParser->setCurrentComponent(component);

            /* Other arguments should be treated as implicit L commands. */
            LPathCommandParser *lCommandParser = new LPathCommandParser();

            for(vector<float>::size_type i = 2; i < arguments.size(); i += 2) {
                vector<float> lArguments;
                lArguments.push_back(arguments[i]);
                lArguments.push_back(arguments[i + 1]);

                char lCommand = dataParser->isRelativeCommand(command) ?
                        'l' : 'L';

                lCommandParser->parse(path, lCommand, dataParser, lArguments);
            }

            delete lCommandParser;
        }
    }
}
