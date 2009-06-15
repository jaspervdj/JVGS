#ifndef JVGS_SKETCH_SKEWYTRANSFORMCOMMAND_H
#define JVGS_SKETCH_SKEWYTRANSFORMCOMMAND_H

#include "TransformCommand.h"

namespace jvgs
{
    namespace sketch
    {
        class SkewYTransformCommand: public TransformCommand
        {
            private:
            public:
                SkewYTransformCommand();
                virtual ~SkewYTransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                                   const std::vector<float> &arguments) const;
        };
    }
}

#endif
