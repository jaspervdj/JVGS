#include "LPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/LineSegment.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        LPathCommandParser::LPathCommandParser()
        {
        }

        LPathCommandParser::~LPathCommandParser()
        {
        }

        void LPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            /* We take the vectors two by two and add lines to the
             * path component. */
            for(vector<float>::size_type  i = 0; i < arguments.size(); i += 2) {
                Vector2D previous = dataParser->getCurrentPoint();
                Vector2D current(arguments[i], arguments[i + 1]);
                current = dataParser->toAbsoluteSpace(command, current);

                LineSegment *segment = new LineSegment(
                        dataParser->toWorldSpace(previous),
                        dataParser->toWorldSpace(current));
                dataParser->getCurrentComponent()->addSegment(segment);

                dataParser->setCurrentPoint(current);
            }

            dataParser->setLastControlPoint(dataParser->getCurrentPoint());
        }
    }
}
