#include "ScriptManager.h"
#include <lua.hpp>

#include "../core/LogManager.h"
#include "../core/DataManager.h"
using namespace jvgs::core;

using namespace std;

/* The compiler/linker needs to know we're dealing with c and not c++. */
extern "C"
{
    /* Header for the opening of the jvgs lua module. */
    extern int luaopen_jvgslua(lua_State *L);
}

namespace jvgs
{
    namespace bind
    {
        ScriptManager::ScriptManager()
        {
            /* Create a new lua state. */
            luaState = lua_open();

            /* Open the standard libs and our own module. */
            luaL_openlibs(luaState);
            luaopen_jvgslua(luaState);
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
            DataManager *dataManager = DataManager::getInstance();

            /* Load the file. */
            int result = luaL_dofile(luaState,
                    dataManager->expand(fileName).c_str());

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
