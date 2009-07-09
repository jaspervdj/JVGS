#ifndef JVGS_SKETCH_SKETCH_H
#define JVGS_SKETCH_SKETCH_H

#include <string>
#include <vector>
#include <map>
#include "../math/Vector2D.h"
#include "../video/Renderer.h"
#include "../video/ListManager.h"

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
                video::ListManager::List list;

            public:
                /** Constructor.
                 *  @param fileName Svg file to parse.
                 */
                Sketch(const std::string &fileName);

                /** Destructor.
                 */
                virtual ~Sketch();

                /** Get the filename this sketch was loaded from.
                 *  @return The filename this sketch was loaded from.
                 */
                virtual const std::string &getFileName() const;

                /** Set the size of this sketch in pixels.
                 *  @param size The new size.
                 */
                virtual void setSize(const math::Vector2D &size);

                /** Get the size from this sketch in pixels.
                 *  @return The sketch size in pixels.
                 */
                virtual const math::Vector2D &getSize() const;

                /** Set the root group for this sketch. This root
                 *  group should not have any tranformation, and
                 *  just contain the actual contents of the sketch.
                 *  @param root The new root group.
                 */
                virtual void setRoot(Group *root);

                /** Get the root group from this sketch. This group
                 *  will contain all sketch elements.
                 *  @return The root group.
                 */
                virtual Group *getRoot() const;

                /** Render this sketch. This renders a previously
                 *  compiled display list of the sketch, in order
                 *  to speed things up a little.
                 */
                virtual void render() const;
        };
    }
}

#endif
