#include "PathSegment.h"

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        PathSegment::PathSegment(char command, const vector<float> &arguments)
        {
            this->command = command;
            this->arguments = arguments;
        }

        PathSegment::~PathSegment()
        {
        }

        char PathSegment::getCommand() const
        {
            return command;
        }

        bool PathSegment::isRelativeCommand() const
        {
            return command >= 'a' && command <= 'z';
        }

        char PathSegment::getLowerCaseCommand() const
        {
            if(!isRelativeCommand())
                return command - 'A' + 'a';
            else
                return command;
        }

        int PathSegment::getNumberOfArguments() const
        {
            return arguments.size();
        }

        float PathSegment::getArgument(int index) const
        {
            return arguments[index];
        }
    }
}
