#ifndef JVGS_GAME_PATROLLINGCONTROLLER_H
#define JVGS_GAME_PATROLLINGCONTROLLER_H

#include "Controller.h"

namespace jvgs
{
    namespace game
    {
        /** A controller that makes the entity patrol between two points.
         */
        class PatrollingController: public Controller
        {
            private:
                /** First point. */
                float x1;

                /** Second point. */
                float x2;

                /** If we are going to x1. */
                bool toX1;

            protected:
                /* Override
                 */
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param x1 First patrol point.
                 *  @param x2 Second control point.
                 */
                PatrollingController(Entity *entity, float x1, float x2);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                PatrollingController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~PatrollingController();

                /* Override
                 */
                virtual void affect(float ms);
        };
    }
}

#endif
