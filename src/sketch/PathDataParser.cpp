#include "PathDataParser.h"
#include "Path.h"
#include "PathComponent.h"
#include "PathCommandParser.h"
#include "LPathCommandParser.h"
#include "MPathCommandParser.h"
#include "ZPathCommandParser.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <sstream>
#include <iostream>
using namespace std;

using namespace jvgs::math;

namespace jvgs
{
    namespace sketch
    {
        const string PathDataParser::COMMANDS = "MmLlHhVvCcSsQqTtAaZz";

        PathDataParser::PathDataParser(Path *path, const string &data)
        {
            this->path = path;
            this->data = data;

            currentComponent = 0;
            lastSegment = 0;

            commandParsers['l'] = new LPathCommandParser(this);
            commandParsers['m'] = new MPathCommandParser(this);
            commandParsers['z'] = new ZPathCommandParser(this);

            matrix = path->getCompleteMatrix();
        }

        PathDataParser::~PathDataParser()
        {
            for(map<char, PathCommandParser*>::iterator iterator =
                    commandParsers.begin(); iterator != commandParsers.end();
                    iterator++)
                delete iterator->second;
        }

        PathComponent *PathDataParser::getCurrentComponent() const
        {
            return currentComponent;
        }

        void PathDataParser::setCurrentComponent(
                PathComponent *currentComponent)
        {
            this->currentComponent = currentComponent;
        }
        
        PathSegment *PathDataParser::getLastSegment() const
        {
            return lastSegment;
        }

        const Vector2D &PathDataParser::getStartingPoint() const
        {
            return startingPoint;
        }

        void PathDataParser::setStartingPoint(const Vector2D &startingPoint)
        {
            this->startingPoint = startingPoint;
        }

        const Vector2D &PathDataParser::getCurrentPoint() const
        {
            return currentPoint;
        }

        void PathDataParser::setCurrentPoint(const Vector2D &currentPoint)
        {
            this->currentPoint = currentPoint;
        }

        const Vector2D &PathDataParser::getLastControlPoint() const
        {
            return lastControlPoint;
        }

        void PathDataParser::setLastControlPoint(const
                Vector2D &lastControlPoint)
        {
            this->lastControlPoint = lastControlPoint;
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
            map<char, PathCommandParser*>::iterator iterator =
                    commandParsers.find(lowerCommand(command));

            if(iterator != commandParsers.end()) {
                PathCommandParser *commandParser = iterator->second;
                commandParser->parse(path, command, arguments);
            } else {
                LogManager::getInstance()->warning(
                        "%c path command is not implemented.", command);
            }
        }

        bool PathDataParser::isRelativeCommand(char command) const
        {
            return command >= 'a' && command <= 'z';
        }

        char PathDataParser::lowerCommand(char command) const
        {
            return (command >= 'a' && command <= 'z' ?
                    command : command - 'A' + 'a');
        }

        Vector2D PathDataParser::toAbsoluteSpace(char command,
                const Vector2D &v) const
        {
            if(isRelativeCommand(command))
                return v + currentPoint;
            else
                return v;
        }

        Vector2D PathDataParser::toWorldSpace(const Vector2D &v) const
        {
            return matrix * v;
        }
    }
}
