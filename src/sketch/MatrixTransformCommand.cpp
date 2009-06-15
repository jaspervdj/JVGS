#include "MatrixTransformCommand.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        MatrixTransformCommand::MatrixTransformCommand()
        {
        }

        MatrixTransformCommand::~MatrixTransformCommand()
        {
        }

        void MatrixTransformCommand::apply(AffineTransformationMatrix &matrix,
                                           const vector<float> &arguments) const
        {
            if(arguments.size() != 6) {
                LogManager::getInstance()->error("Matrix transform command needs 6 arguments, %d given.",
                        arguments.size());
            }

            LogManager::getInstance()->message("Matrix transform:\n------\n%f   %f   %f\n%f   %f   %f\n-----",
            arguments[0], arguments[2], arguments[4], arguments[1], arguments[3], arguments[5]);

            matrix *= AffineTransformationMatrix(arguments[0], arguments[2], arguments[4],
                                                 arguments[1], arguments[3], arguments[5]);
        }
    }
}
