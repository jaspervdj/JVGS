#include "SkewYTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        SkewYTransformCommand::SkewYTransformCommand()
        {
        }

        SkewYTransformCommand::~SkewYTransformCommand()
        {
        }

        void SkewYTransformCommand::apply(AffineTransformationMatrix &matrix,
                const vector<float> &arguments) const
        {
            if(arguments.size() == 1) {
                matrix.skewY(arguments[0]);
            } else {
                LogManager::getInstance()->error("SkewY transformation needs 1 argument, %d given.",
                        arguments.size());
            }
        }
    }
}
