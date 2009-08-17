#include "bind/ScriptManager.h"
using namespace jvgs::bind;

#include "core/LogManager.h"
using namespace jvgs::core;

#include <string>
using namespace std;

int main(int argc, char **argv)
{
    ScriptManager *scriptManager = ScriptManager::getInstance();

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
