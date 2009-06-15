#include "SkewXTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        SkewXTransformCommand::SkewXTransformCommand()
        {
        }

        SkewXTransformCommand::~SkewXTransformCommand()
        {
        }

        void SkewXTransformCommand::apply(AffineTransformationMatrix &matrix,
                const vector<float> &arguments) const
        {
            if(arguments.size() == 1) {
                matrix.skewX(arguments[0]);
            } else {
                LogManager::getInstance()->error("SkewX transformation needs 1 argument, %d given.",
                        arguments.size());
            }
        }
    }
}
