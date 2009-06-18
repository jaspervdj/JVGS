#ifndef JVGS_SKETCH_PATHSEGMENT_H
#define JVGS_SKETCH_PATHSEGMENT_H

#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class PathSegment
        {
            private:
                char command;
                std::vector<float> arguments;

            public:
                PathSegment(char command, const std::vector<float> &arguments);
                virtual ~PathSegment();

                char getCommand() const;
                bool isRelativeCommand() const;
                char getLowerCaseCommand() const;

                int getNumberOfArguments() const;
                float getArgument(int index) const;
        };
    }
}

#endif
