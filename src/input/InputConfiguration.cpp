#include "InputConfiguration.h"

#include "../core/LogManager.h"
using namespace jvgs::core;

using namespace std;

namespace jvgs
{
    namespace input
    {
        InputConfiguration::InputConfiguration()
        {
        }

        InputConfiguration::~InputConfiguration()
        {
        }

        InputConfiguration *InputConfiguration::getConfiguration()
        {
            static InputConfiguration configuration;
            return &configuration;
        }

        const Key &InputConfiguration::getKey(const string &action)
        {
            map<string, Key>::iterator result = keys.find(action);
            if(result != keys.end())
                return result->second;
            else
                LogManager::getInstance()->error(
                        "No key defined for action '%s'", action.c_str());
        }

        void InputConfiguration::setKey(const string &action, const Key &key)
        {
            keys[action] = key;
        }
    }
}
