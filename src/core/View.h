#ifndef JVGS_CORE_VIEW_H
#define JVGS_CORE_VIEW_H

namespace jvgs
{
    namespace core
    {
        /** Abstract class representing something visible that must be updated.
         *  Also, these objects can be marked as garbage.
         */
        class View
        {
            private:
                bool garbage;

            public:
                /** Constructor.
                 */
                View();

                /** Destructor.
                 */
                virtual ~View();

                /** See if this object is garbage. When garbage, it should be
                 *  removed.
                 *  @return If this entity is garbage.
                 */
                virtual bool isGarbage() const;

                /** Mark this view as being garbage. It will be removed later.
                 */
                virtual void setGarbage();

                /** Update the view.
                 *  @param ms Milliseconds to update for.
                 */
                virtual void update(float ms) = 0;

                /** Render the view.
                 */
                virtual void render() = 0;
        };
    }
}

#endif
