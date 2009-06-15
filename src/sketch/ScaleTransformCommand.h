#ifndef JVGS_SKETCH_SCALETRANSFORMCOMMAND_H
#define JVGS_SKETCH_SCALETRANSFORMCOMMAND_H

#include "TransformCommand.h"

namespace jvgs
{
    namespace sketch
    {
        class ScaleTransformCommand: public TransformCommand
        {
            private:
            public:
                ScaleTransformCommand();
                virtual ~ScaleTransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                                   const std::vector<float> &arguments) const;
        };
    }
}

#endif
