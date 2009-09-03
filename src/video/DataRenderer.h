#ifndef JVGS_VIDEO_DATARENDERER_H
#define JVGS_VIDEO_DATARENDERER_H

#include "Renderer.h"
#include <vector>

namespace jvgs
{
    namespace video
    {
        /** A renderer that keeps all vectors it receives. Used for data
         *  analysis purposes.
         */
        class DataRenderer: public Renderer
        {
            private:
                /** Vector list. */
                std::vector<math::Vector2D> data;

            public:
                /** Constructor.
                 */
                DataRenderer();

                /** Destructor.
                 */
                virtual ~DataRenderer();

                /* Override
                 */
                virtual void vector(const math::Vector2D &vector);

                /** Get the vector data.
                 *  @return The vector data.
                 */
                virtual std::vector<math::Vector2D> *getData();
        };
    }
}

#endif
