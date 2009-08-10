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
        CPathCommandParser::CPathCommandParser()
        {
        }

        CPathCommandParser::~CPathCommandParser()
        {
        }

        void CPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            for(vector<float>::size_type i = 0; i < arguments.size(); i += 6) {

                /* Get the defining points. */
                Vector2D previous = dataParser->getCurrentPoint();
                Vector2D control1(arguments[i], arguments[i + 1]);
                Vector2D control2(arguments[i + 2], arguments[i + 3]);
                Vector2D current(arguments[i + 4], arguments[i + 5]);

                /* Convert to absolute space. */
                control1 = dataParser->toAbsoluteSpace(command, control1);
                control2 = dataParser->toAbsoluteSpace(command, control2);
                current = dataParser->toAbsoluteSpace(command, current);

                /* Convert to world space and create the curve. */
                CubicCurve *segment = new CubicCurve(
                        dataParser->toWorldSpace(previous),
                        dataParser->toWorldSpace(control1),
                        dataParser->toWorldSpace(control2),
                        dataParser->toWorldSpace(current));
                dataParser->getCurrentComponent()->addSegment(segment);

                dataParser->setLastControlPoint(control2);
                dataParser->setCurrentPoint(current);
            }
        }
    }
}
