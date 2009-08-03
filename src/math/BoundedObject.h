#ifndef JVGS_MATH_BOUNDEDOBJECT_H
#define JVGS_MATH_BOUNDEDOBJECT_H

namespace jvgs
{
    namespace math
    {
        class BoundingBox;
        
        /** An object that has a bounding box around it.
         */
        class BoundedObject
        {
            private:
            public:
                /** Constructor.
                 */
                BoundedObject();

                /** Destructor.
                 */
                virtual ~BoundedObject();

                /** Get the bounding box for this object.
                 *  @return The bounding box for this object.
                 */
                virtual BoundingBox *getBoundingBox() = 0;
        };
    }
}

#endif
