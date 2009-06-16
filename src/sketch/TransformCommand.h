#ifndef JVGS_SKETCH_TRANSFORMCOMMAND_H
#define JVGS_SKETCH_TRANSFORMCOMMAND_H

#include <vector>
#include "../math/AffineTransformationMatrix.h"

namespace jvgs
{
    namespace sketch
    {
        class TransformCommand
        {
            private:
            public:
                TransformCommand();
                virtual ~TransformCommand();

                virtual void apply(math::AffineTransformationMatrix &matrix,
                        const std::vector<float> &arguments) const = 0;
        };
    }
}

#endif
