#include "StyleMap.h"

using namespace jvgs::video;

#include "../core/LogManager.h"
using namespace jvgs::core;

#include <sstream>
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        StyleMap::StyleMap(StyleMap *parent)
        {
            this->parent = parent;
        }

        StyleMap::~StyleMap()
        {
        }

        void StyleMap::load(const string &data)
        {
            stringstream in(data);

            string line;
            while(in >> line) {

                string::size_type colon = line.find_first_of(':');
                while(colon != string::npos) {

                    string::size_type statementEnd =
                            line.find_first_of(';', colon);

                    string statement;
                    if(statementEnd == string::npos) {
                        statement = line;
                        line = "";
                    } else {
                        statement = line.substr(0, statementEnd);
                        line = line.erase(0, statementEnd + 1);
                    }

                    string key = trim(statement.substr(0, colon));
                    string value = trim(statement.substr(colon + 1));

                    values[key] = value;

                    colon = line.find_first_of(':');
                }
            }
        }

        bool StyleMap::hasValue(const string &key)
        {
            if(values.find(key) != values.end())
                return true;
            else if(parent)
                return parent->hasValue(key);
            else
                return false;
        }

        void StyleMap::setValue(const string &key, const string &value)
        {
            values[key] = value;
        }

        string StyleMap::getValue(const string &key)
        {
            map<string,string>::iterator iterator = values.find(key);
            if(iterator == values.end()) {
                return parent ? parent->getValue(key) : "";
            } else
                return iterator->second;
        }

        float StyleMap::getValueAsFloat(const string &key)
        {
            stringstream converter(getValue(key));
            float f;
            converter >> f;
            return f;
        }

        Color StyleMap::getValueAsColor(const string &key)
        {
            string value = getValue(key);
            return parseColor(value);
        }
    }
}
