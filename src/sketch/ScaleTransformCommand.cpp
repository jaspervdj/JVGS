#include "ScaleTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        ScaleTransformCommand::ScaleTransformCommand()
        {
        }

        ScaleTransformCommand::~ScaleTransformCommand()
        {
        }

        void ScaleTransformCommand::apply(AffineTransformationMatrix &matrix,
                                          const vector<float> &arguments) const
        {
            if(arguments.size() == 1) {
                matrix.scale(Vector2D(arguments[0], arguments[0]));
            } else if(arguments.size() == 2) {
                matrix.scale(Vector2D(arguments[0], arguments[1]));
            } else {
                LogManager::getInstance()->error(
                        "Scale transform needs 1 or 2 arguments, %d given.",
                        arguments.size());
            }
        }
    }
}
