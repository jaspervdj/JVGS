#include "RotateTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

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

        void RotateTransformCommand::apply(math::AffineTransformationMatrix &matrix,
                const std::vector<float> &arguments) const
        {
            if(arguments.size() == 1) {
                matrix.rotate(arguments[0]);
            } else if(arguments.size() == 3) {
                matrix.rotate(arguments[0], arguments[1], arguments[2]);
            } else {
                LogManager::getInstance()->error("Rotate transformation needs 1 or 3 arguments, %d given.",
                        arguments.size());
            }
        }
    }
}
