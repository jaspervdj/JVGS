#include "bind/ScriptManager.h"
using namespace jvgs::bind;

#include "core/LogManager.h"
using namespace jvgs::core;

#include <string>
using namespace std;

/* Needed on windows to link main with SDLmain. */
#include <SDL/SDL.h>

int main(int argc, const char **argv)
{
    ScriptManager *scriptManager = ScriptManager::getInstance();
    scriptManager->setArguments(argc, argv);

    /* File to execute. */
    string fileName;

    if(argc < 2) {
        /* Some default. */
        fileName = "main.lua";
    } else {
        fileName = argv[1];
    }

    scriptManager->runScript(fileName);

    return 0;
}
