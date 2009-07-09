#ifndef JVGS_SKETCH_GROUP_H
#define JVGS_SKETCH_GROUP_H

#include "SketchElement.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class StyleMap;

        /** An svg group.
         */
        class Group: public SketchElement
        {
            private:
                std::vector<SketchElement*> sketchElements;

            public:
                /** Constructor.
                 *  @param parent Parent of the SketchElement.
                 */
                Group(SketchElement *parent);

                /** Desturctor.
                 */
                virtual ~Group();

                /** Get the SketchElement type.
                 *  @return The SketchElement type.
                 */
                virtual Type getType() const;

                /** Add a SketchElement to this group.
                 *  @param sketchElement element to be added.
                 */
                virtual void addSketchElement(SketchElement *sketchElement);

                /** Get the number of sketch elements in this group.
                 *  @return The number of sketch elements in this group.
                 */
                virtual int getNumberOfSketchElements() const;

                /** Get a certain SketchElement by index.
                 *  @param index Index of the SketchElement to retrieve.
                 *  @return The requested sketch element.
                 */
                virtual SketchElement *getSketchElement(int index) const;

                /** Render the element.
                 *  @param renderer Renderer to use.
                 */
                virtual void render(video::Renderer *renderer) const;
        };
    }
}

#endif
