#include "QPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/QuadraticCurve.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        QPathCommandParser::QPathCommandParser()
        {
        }

        QPathCommandParser::~QPathCommandParser()
        {
        }

        void QPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            for(vector<float>::size_type i = 0; i < arguments.size(); i += 4) {

                /* Get the defining points. */
                Vector2D previous = dataParser->getCurrentPoint();
                Vector2D control(arguments[i], arguments[i + 1]);
                Vector2D current(arguments[i + 2], arguments[i + 3]);

                /* Convert to absolute space. */
                control = dataParser->toAbsoluteSpace(command, control);
                current = dataParser->toAbsoluteSpace(command, current);

                /* Convert to world space and create the curve. */
                QuadraticCurve *segment = new QuadraticCurve(
                        dataParser->toWorldSpace(previous),
                        dataParser->toWorldSpace(control),
                        dataParser->toWorldSpace(current));
                dataParser->getCurrentComponent()->addSegment(segment);

                dataParser->setLastControlPoint(control);
                dataParser->setCurrentPoint(current);
            }
        }
    }
}
