#ifndef JVGS_INPUT_INPUTCONFIGURATION_H
#define JVGS_INPUT_INPUTCONFIGURATION_H

#include <map>
#include <string>
#include "Key.h"

namespace jvgs
{
    namespace input
    {
        /** Global input configuration.
         */
        class InputConfiguration
        {
            private:
                /** Internal map */
                std::map<std::string, Key> keys;

            protected:
                /** Constructor.
                 */
                InputConfiguration();

                /** Destructor.
                 */
                virtual ~InputConfiguration();

            public:
                /** Get the configuration.
                 *  @return The global input configuration.
                 */
                static InputConfiguration *getConfiguration();

                /** Get the key associated to an action.
                 *  @param action Action to get the key for.
                 *  @return The requested key.
                 */
                const Key &getKey(const std::string &action);

                /** Sets the key associated to an action.
                 *  @param action Action to set the key for.
                 *  @param key Key to set.
                 */
                void setKey(const std::string &action, const Key &key);
        };
    }
}

#endif
