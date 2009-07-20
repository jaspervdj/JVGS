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
        class SketchElement;

        class Sketch
        {
            private:
                /** Name of the file where this sketch was loaded from. */
                std::string fileName;

                /** Size of the sketch in pixels. */
                math::Vector2D size;

                /** Root group of the sketch. */
                Group *root;

                /** Display list to speed up rendering. */
                video::ListManager::List list;

                /** Map for quicly accessing elements by id. */
                std::map<std::string, SketchElement*> ids;

            public:
                /** Constructor.
                 *  @param fileName Svg file to parse.
                 */
                Sketch(const std::string &fileName);

                /** Constructor. Creates a sketch of the given size.
                 *  @param size Size of the sketch.
                 */
                Sketch(const math::Vector2D &size);

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

                /** Set the root group for this sketch. This root group should
                 *  not have any tranformation, and just contain the actual
                 *  contents of the sketch. This function should only be called
                 *  once for this sketch.
                 *  @param root The new root group.
                 */
                virtual void setRoot(Group *root);

                /** Get the root group from this sketch. This group will contain
                 *  all sketch elements.
                 *  @return The root group.
                 */
                virtual Group *getRoot() const;

                /** Find a SketchElement by it's id.
                 *  @param id Id to look for.
                 *  @return The found SketchElement or 0.
                 */
                virtual SketchElement *getElementById(const std::string &id);

                /** Render this sketch. This renders a previously compiled
                 *  display list of the sketch, in order to speed things up a
                 *  little.
                 */
                virtual void render() const;

            protected:
                /** Collect all ids from the given group and put them in a map
                 *  so they can be accessed more quickly. This method works
                 *  recursively. This will not add group's id, only those of
                 *  it's children.
                 *  @param group Group to collect id's from.
                 */
                virtual void collectIds(Group *group);
        };
    }
}

#endif
