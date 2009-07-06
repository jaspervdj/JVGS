#ifndef JVGS_SKETCH_PATH_H
#define JVGS_SKETCH_PATH_H

#include "SketchElement.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class PathComponent;

        /** A path is a class that represents an svg path.
         */
        class Path: public SketchElement
        {
            private:
                std::vector<PathComponent*> components;

            public:
                /** Constructor.
                 *  @param parent Parent of the path.
                 */
                Path(SketchElement *parent);

                /** Destructor.
                 */
                virtual ~Path();

                /** Get the sketch element type.
                 *  @return The type of sketch element.
                 */
                virtual Type getType() const;

                /** Get the number of components in this path.
                 *  @return The number of components.
                 */
                virtual int getNumberOfComponents() const;

                /** Get a component from the path.
                 *  @param index The component index.
                 *  @return The requested component.
                 */
                virtual PathComponent *getComponent(int index) const;

                /** Add a component to the path.
                 *  @param component Component to be added.
                 */
                virtual void addComponent(PathComponent *component);

                /** Render the path.
                 *  @param renderer Renderer to use.
                 */
                virtual void render(video::Renderer *renderer) const;
        };
    }
}
#endif
