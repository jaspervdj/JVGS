#ifndef JVGS_SKETCH_SKETCH_H
#define JVGS_SKETCH_SKETCH_H

#include <string>
#include <vector>
#include "../math/Vector2D.h"

namespace jvgs
{
    namespace sketch
    {
        class Group;

        class Sketch
        {
            private:
                std::string fileName;
                math::Vector2D size;

                Group *root;

            public:
                /** Constructor.
                 *  @param fileName Svg file to parse.
                 */
                Sketch(const std::string &fileName);

                /** Destructor.
                 */
                virtual ~Sketch();

                virtual const std::string &getFileName() const;

                virtual void setSize(const math::Vector2D &size);
                virtual const math::Vector2D &getSize() const;

                virtual void setRoot(Group *root);
                virtual Group *getRoot() const;

                virtual void render() const;
        };
    }
}

#endif
