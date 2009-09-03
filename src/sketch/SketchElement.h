#ifndef JVGS_SKETCH_SKETCHELEMENT_H
#define JVGS_SKETCH_SKETCHELEMENT_H

#include <string>
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"

namespace jvgs
{
    namespace sketch
    {
        class SketchElementRenderer;
        class StyleMap;

        enum SketchElementType
        {
            SKETCHELEMENTTYPE_GROUP,
            SKETCHELEMENTTYPE_PATH
        };

        class SketchElement
        {
            private:
                SketchElement *parent;
                math::AffineTransformationMatrix matrix;
                std::string id;

            public:
                SketchElement(SketchElement *parent);
                virtual ~SketchElement();

                virtual SketchElementType getType() const = 0;

                virtual SketchElement *getParent() const;

                virtual void setMatrix(
                        const math::AffineTransformationMatrix &matrix);

                virtual const math::AffineTransformationMatrix &getMatrix()
                        const;

                virtual math::AffineTransformationMatrix getCompleteMatrix()
                        const;

                virtual const std::string &getId() const;
                virtual void setId(const std::string &id);

                /** Finishes the SketchElement, caches some stuff. After this,
                 *  do not modify this SketchElement anymore.
                 */
                virtual void finnish() = 0;

                virtual void render() const = 0;
        };
    }
}

#endif
