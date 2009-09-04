#ifndef JVGS_SKETCH_PATH_H
#define JVGS_SKETCH_PATH_H

#include "../math/BoundedObject.h"
#include "../math/BoundingBox.h"
#include "SketchElement.h"
#include "../video/ListManager.h"
#include <vector>

namespace jvgs
{
    namespace sketch
    {
        class PathComponent;

        /** A path is a class that represents an svg path.
         */
        class Path: public SketchElement, public math::BoundedObject
        {
            private:
#               ifndef SWIG
                    static const float SUBDIVIDE_LENGTH;
#               else
                    static float SUBDIVIDE_LENGTH;
#               endif

                std::vector<PathComponent*> components;
                
                /** Display list of this path. */
                video::ListManager::List list;

                /** Bounding box. */
                math::BoundingBox *boundingBox;

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
                virtual SketchElementType getType() const;

                /** Get the length to subdivide the curves in.
                 *  @return The subdivide length.
                 */
                static const float &getSubdivideLength();

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

                /* Override
                 */
                virtual void finnish();

                /* Override
                 */
                virtual void render() const;

                /* Override
                 */
                virtual void render(video::Renderer *renderer);

                /* Override
                 */
                virtual math::BoundingBox *getBoundingBox();
        };
    }
}
#endif
