#ifndef JVGS_SKETCH_MATRIXTRANSFORMCOMMAND_H
#define JVGS_SKETCH_MATRIXTRANSFORMCOMMAND_H

#include "TransformCommand.h"

namespace jvgs
{
    namespace sketch
    {
        class MatrixTransformCommand: public TransformCommand
        {
            private:
            public:
                MatrixTransformCommand();
                virtual ~MatrixTransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                                   const std::vector<float> &arguments) const;
        };
    }
}

#endif
