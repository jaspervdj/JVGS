#ifndef JVGS_SKETCH_SKEWXTRANSFORMCOMMAND_H
#define JVGS_SKETCH_SKEWXTRANSFORMCOMMAND_H

#include "TransformCommand.h"

namespace jvgs
{
    namespace sketch
    {
        class SkewXTransformCommand: public TransformCommand
        {
            private:
            public:
                SkewXTransformCommand();
                virtual ~SkewXTransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                                   const std::vector<float> &arguments) const;
        };
    }
}

#endif
