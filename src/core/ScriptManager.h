#ifndef JVGS_CORE_SCRIPTMANAGER_H
#define JVGS_CORE_SCRIPTMANAGER_H

#include <string>
struct lua_State;

namespace jvgs
{
    namespace core
    {
        /** A class to run scripts.
         */
        class ScriptManager
        {
            private:
                /** The lua state. */
                lua_State *luaState;

            protected:
                /** Constructor.
                 */
                ScriptManager();

                /** Destructor.
                 */
                virtual ~ScriptManager();
            public:
                /** Get the ScriptManager instance.
                 *  @return The ScriptManager instance.
                 */
                static ScriptManager *getInstance();

                /** Run a script.
                 *  @param fileName File name of the script to run.
                 */
                void runScript(const std::string &fileName);

                /** Run a piece of code.
                 *  @param code Code to run.
                 */
                void runCode(const std::string &code);
        };
    }
}

#endif
