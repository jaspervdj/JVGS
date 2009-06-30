#include "PathDataParser.h"
#include "Path.h"

#include <sstream>
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        const string PathDataParser::COMMANDS = "MmLlHhVvCcSsQqTtAaZz";

        PathDataParser::PathDataParser(Path *path, const string &data)
        {
            this->path = path;
            this->data = data;
        }

        PathDataParser::~PathDataParser()
        {
        }

        void PathDataParser::parse()
        {
            string::size_type start = data.find_first_of(COMMANDS);
            if(start == string::npos)
                start = 0;

            string::size_type end = data.find_first_of(COMMANDS, start + 1);

            while(end != string::npos) {
                command(data.substr(start, end - start));
                start = end;
                end = data.find_first_of(COMMANDS, start + 1);
            }

            /* Add last command. */
            command(data.substr(start));
        }

        void PathDataParser::command(const string &commandData)
        {
            char command = commandData[0];
            vector<string> splitted;
            vector<float> arguments;
            string argumentsData = commandData.substr(1);
            replaceAll(argumentsData, "-", " -");
            split(argumentsData, ", ", splitted);
            for(vector<string>::iterator iterator = splitted.begin();
                    iterator != splitted.end(); iterator++) {
                stringstream converter(*iterator);
                float f;
                converter >> f;
                arguments.push_back(f);
            }

            //path->addSegment(new PathSegment(command, arguments));
            /* DO SOMETHING WITH COMMAND AND ARGUMENTS. */
        }
    }
}
