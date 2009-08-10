#ifndef JVGS_SKETCH_PATHDATAPARSER_H
#define JVGS_SKETCH_PATHDATAPARSER_H

#include "TextParser.h"
#include <string>
#include <map>
#include "../math/Vector2D.h"
#include "../math/PathSegment.h"
#include "../math/AffineTransformationMatrix.h"

namespace jvgs
{
    namespace sketch
    {
        class Path;
        class PathComponent;
        class PathCommandParser;

        class PathDataParser: public TextParser
        {
            private:
#               ifndef SWIG
                    const static std::string COMMANDS;
#               else
                    static std::string COMMANDS;
#               endif

                Path *path;
                std::string data;

                PathComponent *currentComponent;

                math::PathSegment *lastSegment;
                math::Vector2D startingPoint;
                math::Vector2D currentPoint;
                math::Vector2D lastControlPoint;

                static std::map<char, PathCommandParser*> commandParsers;

                math::AffineTransformationMatrix matrix;

            public:

                PathDataParser(Path *path, const std::string &data);
                virtual ~PathDataParser();

                virtual PathComponent *getCurrentComponent() const;
                virtual void setCurrentComponent(PathComponent *component);

                virtual math::PathSegment *getLastSegment() const;

                virtual const math::Vector2D &getStartingPoint() const;
                virtual void setStartingPoint(const math::Vector2D &point);

                virtual const math::Vector2D &getCurrentPoint() const;
                virtual void setCurrentPoint(const math::Vector2D &point);

                virtual const math::Vector2D &getLastControlPoint() const;
                virtual void setLastControlPoint(const math::Vector2D &point);

                virtual void parse();
                virtual void command(const std::string &commandData);
                virtual bool isRelativeCommand(char command) const;
                virtual char lowerCommand(char command) const;

                virtual math::Vector2D toAbsoluteSpace(char command,
                        const math::Vector2D &vector) const;

                virtual math::Vector2D toWorldSpace(
                        const math::Vector2D &vector) const;
        };
    }
}

#endif
