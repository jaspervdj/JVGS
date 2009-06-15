#ifndef JVGS_SKETCH_TRANSLATETRANSFORMCOMMAND_H
#define JVGS_SKETCH_TRANSLATETRANSFORMCOMMAND_H

#include "TransformCommand.h"

namespace jvgs
{
    namespace sketch
    {
        class TranslateTransformCommand: public TransformCommand
        {
            private:
            public:
                TranslateTransformCommand();
                virtual ~TranslateTransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                                   const std::vector<float> &arguments) const;
        };
    }
}

#endif
