#include "ScriptManager.h"
#include "LogManager.h"
#include <lua.hpp>

using namespace std;

namespace jvgs
{
    namespace core
    {
        ScriptManager::ScriptManager()
        {
            luaState = lua_open();
            luaL_openlibs(luaState);
        }

        ScriptManager::~ScriptManager()
        {
            lua_close(luaState);
        }

        ScriptManager *ScriptManager::getInstance()
        {
            static ScriptManager instance;
            return &instance;
        }

        void ScriptManager::runScript(const string &fileName)
        {
            /* Load the file. */
            int result = luaL_dofile(luaState, fileName.c_str());

            /* An error occurred. */
            if(result)
                LogManager::getInstance()->error("%s: %s", fileName.c_str(),
                        lua_tostring(luaState, -1));
        }

        void ScriptManager::runCode(const string &code)
        {
            /* Load the file. */
            int result = luaL_dostring(luaState, code.c_str());

            /* An error occurred. */
            if(result)
                LogManager::getInstance()->error("%s: %s", code.c_str(),
                        lua_tostring(luaState, -1));
        }
    }
}
