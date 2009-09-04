#ifndef JVGS_SKETCH_SKETCH_H
#define JVGS_SKETCH_SKETCH_H

#include <string>
#include <vector>
#include <map>
#include "../math/Vector2D.h"
#include "../video/Renderer.h"
#include "../video/ListManager.h"
#include "../math/BoundingBox.h"
#include "../math/QuadTree.h"

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

                /** List to construct to the tree. */
                std::vector<math::BoundedObject*> boundedObjects;

                /** QuadTree to speed up rendering. */
                math::QuadTree *tree;

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

                /** Finnish the sketch. After calling this, do not add any
                 *  elements anymore.
                 */
                virtual void finnish();

                /** Render this sketch. 
                 */
                virtual void render() const;

                /** Render (at least) a part of this sketch. With large sketches
                 *  this should be a lot quicker. This render method uses a
                 *  QuadTree to search for objects that should be rendered.
                 *  @param boundingBox Part of the sketch to render.
                 */
                virtual void render(math::BoundingBox *boundingBox);

                /** Render the sketch with a given renderer. Slow, because this
                 *  doesn't use display lists. But, this is used to render the
                 *  sketch to a display list, and therefore needed. It also has
                 *  other purposes.
                 *  @param renderer Renderer to use.
                 */
                virtual void render(video::Renderer *renderer);

            protected:
                /** Called to process every element in the sketch. Works
                 *  recursively.
                 *  @param group Group to process.
                 */
                virtual void processElements(Group *group);
        };
    }
}

#endif
