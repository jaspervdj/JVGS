#ifndef JVGS_BIND_SCRIPTMANAGER_H
#define JVGS_BIND_SCRIPTMANAGER_H

#include <string>
#include <vector>
struct lua_State;

namespace jvgs
{
    namespace bind
    {
        /** A class to run scripts.
         */
        class ScriptManager
        {
            private:
                /** The lua state. */
                lua_State *luaState;

                /** The arguments. */
                std::vector<std::string> arguments;

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

                /** Set the command line options. It is a very, very bad idea
                 *  to use this outside of the main function. Aliasing cat to
                 *  rm is, for instance, a better idea.
                 *  @param argc Number of parameters.
                 *  @param argv Parameters.
                 */
                void setArguments(int argc, char *argv[]);

                /** Get the number of arguments given to the jvgs executable.
                 *  @return The number of arguments.
                 */
                int getNumberOfArguments() const;

                /** Get a specific argument.
                 *  @param index Index of the argument.
                 *  @return The requested argument.
                 */
                const std::string &getArgument(int index) const;
        };
    }
}

#endif
