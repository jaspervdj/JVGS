#include "RotateTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        RotateTransformCommand::RotateTransformCommand()
        {
        }

        RotateTransformCommand::~RotateTransformCommand()
        {
        }

        void RotateTransformCommand::apply(AffineTransformationMatrix &matrix,
                const vector<float> &arguments) const
        {
            if(arguments.size() == 1) {
                matrix.rotate(arguments[0]);
            } else if(arguments.size() == 3) {
                matrix.rotate(arguments[0],
                        Vector2D(arguments[1], arguments[2]));
            } else {
                LogManager::getInstance()->error(
                        "Rotate transform needs 1 or 3 arguments, %d given.",
                        arguments.size());
            }
        }
    }
}
