#ifndef JVGS_GAME_INPUTCONTROLLER_H
#define JVGS_GAME_INPUTCONTROLLER_H

#include "../input/KeyListener.h"
#include "../input/InputConfiguration.h"
#include "Controller.h"

namespace jvgs
{
    namespace game
    {
        /** Controller that lets the player control the entity. */
        class InputController: public Controller,
                public jvgs::input::KeyListener
        {
            protected:
                /** Reference to the input configuration. */
                input::InputConfiguration *configuration;

                /* Override
                 */
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to control.
                 */
                InputController(Entity *entity);

                /** Constructor.
                 *  @param entity Entity to control.
                 *  @param element TiXmlElement to load data from.
                 */
                InputController(Entity *entity, TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~InputController();

                /* Override
                 */
                virtual void affect(float ms);

                /* Override
                 */
                virtual void keyPressed(const jvgs::input::Key &key);
        };
    }
}

#endif
