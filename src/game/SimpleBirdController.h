#ifndef JVGS_GAME_SIMPLEBIRDCONTROLLER_H
#define JVGS_GAME_SIMPLEBIRDCONTROLLER_H

#include "Controller.h"
#include <vector>
#include "../math/Vector2D.h"

namespace jvgs
{
    namespace game
    {
        /** A controller that makes an entity follow a path.
         */
        class SimpleBirdController: public Controller
        {
            private:
                /** List of points on the path. */
                std::vector<math::Vector2D> points;

                /** Current target point. */
                int currentPoint;

            protected:
                /* Override
                 */
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param near Turn when get closer than this to a point.
                 */
                SimpleBirdController(Entity *entity);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                SimpleBirdController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~SimpleBirdController();

                /** Add a point to the path.
                 *  @param point Point to add.
                 */
                virtual void addPoint(const math::Vector2D &point);

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
