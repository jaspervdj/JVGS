#include "MPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        MPathCommandParser::MPathCommandParser(PathDataParser *dataParser):
                PathCommandParser(dataParser)
        {
        }

        MPathCommandParser::~MPathCommandParser()
        {
        }

        void MPathCommandParser::parse(Path *path, char command,
                const std::vector<float> &arguments) const
        {
            PathDataParser *dataParser = getDataParser();

            Vector2D translation(arguments[0], arguments[1]);
            translation = dataParser->toAbsoluteSpace(command, translation);

            dataParser->setCurrentPoint(translation);
            dataParser->setStartingPoint(translation);

            PathComponent *component = new PathComponent(path);
            path->addComponent(component);
            dataParser->setCurrentComponent(component);

            /* TODO: other arguments should be treated as implicit
             * L commands. */
        }
    }
}
