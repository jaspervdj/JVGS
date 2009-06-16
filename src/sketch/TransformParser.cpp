#include "TransformParser.h"
#include "TransformCommand.h"
#include "RotateTransformCommand.h"
#include "ScaleTransformCommand.h"
#include "TranslateTransformCommand.h"
#include "MatrixTransformCommand.h"
#include "SkewXTransformCommand.h"
#include "SkewYTransformCommand.h"

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
using namespace jvgs::math;

#include "../core/LogManager.h"
using namespace jvgs::core;

namespace jvgs
{
    namespace sketch
    {
        TransformParser::TransformParser()
        {
            commands["rotate"] = new RotateTransformCommand();
            commands["scale"] = new ScaleTransformCommand();
            commands["translate"] = new TranslateTransformCommand();
            commands["matrix"] = new MatrixTransformCommand();
            commands["skewX"] = new SkewXTransformCommand();
            commands["skewY"] = new SkewYTransformCommand();
        }

        TransformParser::~TransformParser()
        {
            for(map<string, TransformCommand*>::iterator iterator =
                    commands.begin(); iterator != commands.end(); iterator++) {
                delete iterator->second;
            }
        }

        AffineTransformationMatrix TransformParser::parse(const string &data)
        {
            AffineTransformationMatrix matrix;

            string::size_type position = 0;
            while(position < data.size() && position != string::npos) {
                string::size_type opening = data.find_first_of('(', position);
                string command = data.substr(position, opening - position);
                command = trim(command);
                position = data.find_first_of(')', opening);

                string argumentString = data.substr(opening + 1,
                        position - opening - 1);
                vector<string> arguments;
                split(argumentString, ',', arguments);

                vector<float> floatArguments;

                for(vector<string>::iterator iterator = arguments.begin(); 
                        iterator != arguments.end(); iterator++ )
                {
                    float f;
                    stringstream converter(*iterator);
                    converter >> f;
                    floatArguments.push_back(f);
                }

                map<string, TransformCommand*>::iterator iterator =
                        commands.find(command);

                if(iterator != commands.end()) {
                    iterator->second->apply(matrix, floatArguments);
                } else {
                    LogManager::getInstance()->warning(
                            "Unknown tranform command \"%s\"", command.c_str());
                }

                position++;
            }

            return matrix;
        }
    }
}
