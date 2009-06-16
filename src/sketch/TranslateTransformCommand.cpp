#include "TranslateTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        TranslateTransformCommand::TranslateTransformCommand()
        {
        }

        TranslateTransformCommand::~TranslateTransformCommand()
        {
        }

        void TranslateTransformCommand::apply(
                AffineTransformationMatrix &matrix,
                const vector<float> &arguments) const
        {
            if(arguments.size() == 1) {
                matrix.translate(Vector2D(arguments[0], 0.0f));
            } else if(arguments.size() == 2) {
                matrix.translate(Vector2D(arguments[0], arguments[1]));
            } else {
                LogManager::getInstance()->error(
                        "Translate transform needs 1 or 2 arguments, %d given.",
                        arguments.size());
            }
        }
    }
}
