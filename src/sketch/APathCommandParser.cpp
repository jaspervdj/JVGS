#include "APathCommandParser.h"
#include "PathDataParser.h"
#include "PathComponent.h"

#include "../math/EllipticalArc.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        APathCommandParser::APathCommandParser()
        {
        }

        APathCommandParser::~APathCommandParser()
        {
        }

        void APathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            /* We take the vectors two by two and add lines to the
             * path component. */
            for(vector<float>::size_type  i = 0; i < arguments.size(); i += 7) {
                Vector2D start = dataParser->getCurrentPoint();
                Vector2D radius(arguments[i], arguments[i + 1]);
                float xAxisRotation = arguments[i + 2];
                bool largeArc = (bool)(int) arguments[i + 3];
                bool sweep = (bool)(int) arguments[i + 4];
                Vector2D end(arguments[i + 5], arguments[i + 6]);
                end = dataParser->toAbsoluteSpace(command, end);

                EllipticalArc *segment = new EllipticalArc(
                        dataParser->toWorldSpace(start), radius, xAxisRotation,
                        largeArc, sweep, dataParser->toWorldSpace(end));
                dataParser->getCurrentComponent()->addSegment(segment);

                dataParser->setCurrentPoint(end);
            }

            dataParser->setLastControlPoint(dataParser->getCurrentPoint());
        }
    }
}
