#ifndef JVGS_SKETCH_ROTATETRANSFORMCOMMAND_H
#define JVGS_SKETCH_ROTATETRANSFORMCOMMAND_H

#include "TransformCommand.h"

namespace jvgs
{
    namespace sketch
    {
        class RotateTransformCommand: public TransformCommand
        {
            private:
            public:
                RotateTransformCommand();
                virtual ~RotateTransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                                   const std::vector<float> &arguments) const;
        };
    }
}

#endif
